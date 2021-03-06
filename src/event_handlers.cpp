
#include "MyFrameMain.h"
#include <wx/aboutdlg.h>
#include "shiki_api.h"
#include "smotret-anime_api.h"
#include "nlohmann/json.hpp"
#include "MyDialogLogin.h"
#include <fstream>

void MyFrameMain::wxMenuItem_info_menu_selection(wxCommandEvent& event) {
    wxAboutDialogInfo info;
    info.SetIcon(icon);
	info.SetName("sa2");
	info.SetVersion("0.2");
	info.SetDescription("Program to download subtitles from smotret-anime.online");
	info.SetCopyright(wxT("(C) 2020 Alexandr Starovoytov <stewk6@gmail.com>"));
	wxAboutBox(info);
    event.Skip();
}

struct anime_entry {
    std::string name;
    long long id;
};

void get_parsed_anime_list(std::vector<anime_entry>& anime_list, const std::string& server_ans) {
    nlohmann::json ans_json = nlohmann::json::parse(server_ans);
    if (ans_json.is_array()) {
        for (auto& entry : ans_json) {
            std::string anime_name = entry["anime"]["name"];
            long long anime_id = entry["anime"]["id"].get<long long>();
            anime_list.push_back({anime_name, anime_id});
        }
    }
}

void MyFrameMain::wxlistbox_anime_list_update() {
    std::ifstream shiki_login_file(".shiki_login");
    std::string shiki_username;
    if (shiki_login_file.is_open()) {
        shiki_login_file >> shiki_username;
    }
    Update();
    if (shiki_username.size() != 0) {
        Shiki shiki_api(shiki_username);
        std::string ans = shiki_api.api_users_id_anime_rates();
        Update();
        std::vector<anime_entry> anime_list;
        get_parsed_anime_list(anime_list, ans);
        wxListBox_anime_list->Clear();
        anime_ids.clear();
        Update();
        for (auto& anime : anime_list) {
            wxListBox_anime_list->Append(anime.name);
            anime_ids.push_back(anime.id);
        }
    }
}

long long get_parsed_smotret_anime_series_id(const std::string& server_ans) {
    nlohmann::json ans_json = nlohmann::json::parse(server_ans);
    long long res_id = ans_json["data"][0]["id"].get<long long>();
    return res_id;
}



void parse_anime_translations(const std::string& server_ans,
        std::map<std::string, std::vector<translation>>& translations_by_authors) {
    nlohmann::json ans_json = nlohmann::json::parse(server_ans);
    for (auto& translation_entry : ans_json["data"]) {
        if (translation_entry["type"].get<std::string>() == "subRu") {
            translation new_entry;
            new_entry.id = translation_entry["id"].get<long long>();
            new_entry.episodeFull = translation_entry["episode"]["episodeInt"].get<std::string>()
                    + translation_entry["episode"]["episodeType"].get<std::string>();
            std::string authorsSummary = translation_entry["authorsSummary"].get<std::string>();
            if (authorsSummary.size() != 0) {
                translations_by_authors[authorsSummary].push_back(new_entry);
            }
        }
    }
}

void MyFrameMain::wxListBox_anime_choosed(wxCommandEvent& event) {
    int index = wxListBox_anime_list->GetSelection();
    selected_anime_name = wxListBox_anime_list->GetString(index);
    Update();
    long long shiki_id = anime_ids[index];
    SmotretAnime smotret_anime_api;
    std::string ans;
    ans = smotret_anime_api.api_series_get_id_by_shiki_id(shiki_id);    
    Update();
    long long smotret_anime_series_id = get_parsed_smotret_anime_series_id(ans);
    Update();
    ans = smotret_anime_api.api_translations_get_by_seriesId(smotret_anime_series_id);
    Update();
    std::map<std::string, std::vector<translation>> translations_by_authors;
    parse_anime_translations(ans, translations_by_authors);
    Update();
    wxCheckListBox_subs_authors->Clear();
    list_of_translations_by_authors.clear();
    Update();
    for (auto& translation_by_author : translations_by_authors) {
        wxCheckListBox_subs_authors->Append(translation_by_author.first);
        list_of_translations_by_authors.push_back({});
        list_of_translations_by_authors[list_of_translations_by_authors.size() - 1] =
            translation_by_author.second;
    }
    event.Skip(); 
}

void download_selected_subs(const translation& translation_entry, const std::string& selected_anime_name, 
        const std::string& subs_author_name) {
    SmotretAnime smotret_anime_api;
    smotret_anime_api.download_sub_by_translation_id(translation_entry.id, selected_anime_name + "/" +
            subs_author_name + "/", translation_entry.episodeFull + ".ass");
}

void MyFrameMain::wxButton_download_click(wxCommandEvent& event) {
    wxArrayInt selected_authors;
    wxCheckListBox_subs_authors->GetSelections(selected_authors);
    Update();
    if (!wxDirExists(selected_anime_name)) {
        wxMkdir(selected_anime_name);
    }
    Update();
    for (auto& index : selected_authors) {
        std::string subs_author_name = (std::string)wxCheckListBox_subs_authors->GetString(index); 
        if (!wxDirExists(selected_anime_name + "/" + subs_author_name)) {
            wxMkdir(selected_anime_name + "/" + subs_author_name);
        }
        for (auto& translation : list_of_translations_by_authors[index]) {
            download_selected_subs(translation, selected_anime_name, subs_author_name);
            Update();
        }
        Update();
    }
    event.Skip();
}

void MyFrameMain::wxMenuItem_shiki_login_menu_selection( wxCommandEvent& event ) {
    MyDialogLogin* dialog_login_shiki = new MyDialogLogin(nullptr); 
    dialog_login_shiki->ShowModal(); 
    delete dialog_login_shiki;
    event.Skip(); 
}

void MyFrameMain::wxMenuItem_refresh_anime_list_menu_selection(wxCommandEvent& event) {
    wxlistbox_anime_list_update();
    event.Skip();
}
