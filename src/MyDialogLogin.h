
#include "ui.h"

class MyDialogLogin : public DialogLogin {
public:
    virtual void wxStdDialog_ok_button_selected(wxCommandEvent& event);
    MyDialogLogin(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Shiki Login"),
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_DIALOG_STYLE);
    ~MyDialogLogin();
};
