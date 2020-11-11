
#include <wx/wx.h>
#include "MyFrameMain.h"

class App : public wxApp {
public:
    App();
    ~App();
private:
    MyFrameMain* frame_main = nullptr;
public:
    virtual bool OnInit();
};
