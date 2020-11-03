
#include "MyFrameMain.h"

void MyFrameMain::wxMenuItem_info_menu_selection(wxCommandEvent& event) {
    std::cout << "event handled" << std::endl;
    event.Skip();
}

MyFrameMain::MyFrameMain(wxWindow* parent, wxWindowID id, const wxString& title, 
        const wxPoint& pos, const wxSize& size, long style) : FrameMain(parent, id, title, pos, size, style) {

}

MyFrameMain::~MyFrameMain() {

}

