
#include "MyFrameMain.h"
#include <wx/aboutdlg.h>
#include "shiki_api.h"
#include "nlohmann/json.hpp"

void MyFrameMain::wxMenuItem_info_menu_selection(wxCommandEvent& event) {
    wxAboutDialogInfo info;
    info.SetIcon(icon);
	info.SetName("sa2");
	info.SetVersion("0.1");
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
    for (auto& entry : ans_json) {
        std::string anime_name = entry["anime"]["name"];
        long long anime_id = entry["anime"]["id"].get<long long>();
        anime_list.push_back({anime_name, anime_id});
    }
}

void MyFrameMain::wxlistbox_anime_list_update() {
    Shiki shiki_api("stewkk");
    std::string ans = shiki_api.api_users_id_anime_rates();
    Update();
    std::vector<anime_entry> anime_list;
    get_parsed_anime_list(anime_list, ans);
    for (auto& anime : anime_list) {
        wxListBox_anime_list->Append(anime.name);
        anime_ids.push_back(anime.id);
    }
}

void MyFrameMain::wxListBox_anime_choosed(wxCommandEvent& event) {
    int index = wxListBox_anime_list->GetSelection();
    event.Skip(); 
}

