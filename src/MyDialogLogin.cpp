
#include "MyDialogLogin.h"
#include <fstream>

MyDialogLogin::MyDialogLogin(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
        const wxSize& size, long style) : DialogLogin(parent, id, title, pos, size, style) {

}

MyDialogLogin::~MyDialogLogin() {

}

void MyDialogLogin::wxStdDialog_ok_button_selected(wxCommandEvent& event) {
    wxString shiki_username = wxTextCtrl_shiki_login_entry->GetValue();
    std::ofstream shiki_login_file(".shiki_login");
    if (shiki_login_file.is_open()) {
        shiki_login_file << shiki_username;
    }
    event.Skip();
}
