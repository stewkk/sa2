
#include "main.h"

wxIMPLEMENT_APP(App);

App::App() {

}

App::~App() {

}

bool App::OnInit() {
    frame_main = new MyFrameMain(nullptr);
    frame_main->Show();
    frame_main->SetIcon(wxIcon(icon));
    frame_main->wxlistbox_anime_list_update();
    return true;
}

