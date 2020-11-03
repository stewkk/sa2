
#include "wx/wx.h"
#include "main.h"

wxIMPLEMENT_APP(App);

App::App() {

}

App::~App() {

}

bool App::OnInit() {
    frame_main = new MyFrameMain(nullptr);
    frame_main->Show();
    return true;
}

