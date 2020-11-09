
#include "ui.h"
#include "icon.xpm"
#include <vector>

struct translation {
    long long id;
    std::string episodeFull;
};

class MyFrameMain : public FrameMain {
public:
    virtual void wxMenuItem_shiki_login_menu_selection(wxCommandEvent& event);
    virtual void wxMenuItem_info_menu_selection(wxCommandEvent& event);
    virtual void wxListBox_anime_choosed(wxCommandEvent& event);
    virtual void wxButton_download_click(wxCommandEvent& event);
    void wxlistbox_anime_list_update();
    MyFrameMain(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("anime"),
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,600 ),
            long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);
    ~MyFrameMain();
private:
    std::vector<long long> anime_ids;
    std::string selected_anime_name;
    std::vector<std::vector<translation>> list_of_translations_by_authors; 
};
