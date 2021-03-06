///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Nov  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/srchctrl.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/hyperlink.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FrameMain
///////////////////////////////////////////////////////////////////////////////
class FrameMain : public wxFrame
{
	private:

	protected:
		wxMenuBar* wxMenuBar_main;
		wxMenu* wxMenu_main;
		wxSearchCtrl* search;
		wxListBox* wxListBox_anime_list;
		wxCheckListBox* wxCheckListBox_subs_authors;
		wxButton* wxButton_download;

		// Virtual event handlers, override them in your derived class
		virtual void wxMenuItem_refresh_anime_list_menu_selection( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxMenuItem_shiki_login_menu_selection( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxMenuItem_info_menu_selection( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxListBox_anime_choosed( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxButton_download_click( wxCommandEvent& event ) { event.Skip(); }


	public:

		FrameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("anime"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~FrameMain();

};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogLogin
///////////////////////////////////////////////////////////////////////////////
class DialogLogin : public wxDialog
{
	private:

	protected:
		wxHyperlinkCtrl* wxHyperlinkCtrl_shikimori_one_login_link;
		wxTextCtrl* wxTextCtrl_shiki_login_entry;
		wxStdDialogButtonSizer* wxStdDialogButtonSizer_shiki_login_sizer;
		wxButton* wxStdDialogButtonSizer_shiki_login_sizerOK;
		wxButton* wxStdDialogButtonSizer_shiki_login_sizerCancel;

		// Virtual event handlers, override them in your derived class
		virtual void wxStdDialog_cancel_button_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void wxStdDialog_ok_button_selected( wxCommandEvent& event ) { event.Skip(); }


	public:

		DialogLogin( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Shiki Login"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~DialogLogin();

};

