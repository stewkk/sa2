
#include "MyFrameMain.h"
#include <wx/aboutdlg.h>
#include "shiki_api.h"

void MyFrameMain::wxMenuItem_info_menu_selection(wxCommandEvent& event) {
    Shiki api;
    api.api_users_id_anime_rates(1, 1, "s", false);
    wxAboutDialogInfo info;
    info.SetIcon(icon);
	info.SetName("sa2");
	info.SetVersion("0.1");
	info.SetDescription("Program to download subtitles from smotret-anime.online");
	info.SetCopyright(wxT("(C) 2020 Alexandr Starovoytov <stewk6@gmail.com>"));
	wxAboutBox(info);
    event.Skip();
}

