
#include "ui.h"
#include "icon.xpm"
#include <vector>

class MyFrameMain : public FrameMain {
public:
    virtual void wxMenuItem_info_menu_selection(wxCommandEvent& event);
    virtual void wxListBox_anime_choosed(wxCommandEvent& event);
    void wxlistbox_anime_list_update();
    MyFrameMain(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("anime"),
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,600 ),
            long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);
    ~MyFrameMain();
private:
    std::vector<long long> anime_ids;
};

