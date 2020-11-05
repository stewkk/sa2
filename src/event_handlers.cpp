
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

void get_parsed_anime_list(std::vector<std::string>& anime_list, const std::string& server_ans) {
    nlohmann::json ans_json = nlohmann::json::parse(server_ans); 
    for (auto& entry : ans_json) {
        std::string anime_name = entry["anime"]["name"];
        anime_list.push_back(anime_name);
    }
}

void MyFrameMain::wxlistbox_anime_list_update() {
    Shiki shiki_api("stewkk");
    std::string ans = shiki_api.api_users_id_anime_rates();
    Update();
    std::vector<std::string> anime_list;
    get_parsed_anime_list(anime_list, ans);
    for (auto& anime_name : anime_list) {
        wxListBox_anime_list->Append(anime_name);
    }
}

