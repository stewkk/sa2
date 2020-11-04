
#include "MyFrameMain.h"

void MyFrameMain::wxMenuItem_info_menu_selection(wxCommandEvent& event) {
    std::cout << "event handled" << std::endl;
    event.Skip();
}

