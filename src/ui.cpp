///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Nov  3 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ui.h"

///////////////////////////////////////////////////////////////////////////

FrameMain::FrameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,225 ), wxDefaultSize );

	wxMenuBar_main = new wxMenuBar( 0 );
	wxMenu_main = new wxMenu();
	wxMenuItem* wxMenuItem_info;
	wxMenuItem_info = new wxMenuItem( wxMenu_main, wxID_ANY, wxString( wxT("Info") ) , wxEmptyString, wxITEM_NORMAL );
	wxMenu_main->Append( wxMenuItem_info );

	wxMenuItem* wxMenuItem_logout;
	wxMenuItem_logout = new wxMenuItem( wxMenu_main, wxID_ANY, wxString( wxT("Logout") ) , wxEmptyString, wxITEM_NORMAL );
	wxMenu_main->Append( wxMenuItem_logout );
	wxMenuItem_logout->Enable( false );

	wxMenuBar_main->Append( wxMenu_main, wxT("Menu") );

	this->SetMenuBar( wxMenuBar_main );

	wxStatusBar_main = this->CreateStatusBar( 3, wxSTB_SIZEGRIP, wxID_ANY );
	wxStatusBar_main->Hide();

	wxBoxSizer* wxBoxSizer_main;
	wxBoxSizer_main = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* wxBoxSizer_search;
	wxBoxSizer_search = new wxBoxSizer( wxHORIZONTAL );

	search = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,30 ), wxTE_PROCESS_ENTER );
	#ifndef __WXMAC__
	search->ShowSearchButton( true );
	#endif
	search->ShowCancelButton( true );
	search->Hide();
	search->SetMinSize( wxSize( 200,30 ) );
	search->SetMaxSize( wxSize( -1,30 ) );

	wxBoxSizer_search->Add( search, 1, wxALIGN_TOP|wxALL, 5 );


	wxBoxSizer_main->Add( wxBoxSizer_search, 0, wxEXPAND, 5 );

	wxGridSizer* wxGridSizer_lists;
	wxGridSizer_lists = new wxGridSizer( 2, 1, 0, 0 );

	wxListBox_anime_list = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE|wxHSCROLL|wxVSCROLL );
	wxGridSizer_lists->Add( wxListBox_anime_list, 0, wxALL|wxEXPAND, 5 );

	wxArrayString wxCheckListBox_subs_authorsChoices;
	wxCheckListBox_subs_authors = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCheckListBox_subs_authorsChoices, 0 );
	wxGridSizer_lists->Add( wxCheckListBox_subs_authors, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );


	wxBoxSizer_main->Add( wxGridSizer_lists, 1, wxEXPAND, 5 );

	wxBoxSizer* wxBoxSizer_btn_download;
	wxBoxSizer_btn_download = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer_btn_download->SetMinSize( wxSize( -1,30 ) );
	wxButton_download = new wxButton( this, wxID_ANY, wxT("Download"), wxDefaultPosition, wxSize( -1,40 ), wxBORDER_NONE );

	wxButton_download->SetBitmapMargins( wxSize( 0,0 ) );
	wxButton_download->SetMinSize( wxSize( 100,40 ) );
	wxButton_download->SetMaxSize( wxSize( -1,100 ) );

	wxBoxSizer_btn_download->Add( wxButton_download, 1, wxALIGN_BOTTOM, 5 );


	wxBoxSizer_main->Add( wxBoxSizer_btn_download, 0, wxALIGN_BOTTOM|wxEXPAND, 5 );


	this->SetSizer( wxBoxSizer_main );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	wxMenu_main->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( FrameMain::wxMenuItem_info_menu_selection ), this, wxMenuItem_info->GetId());
	wxListBox_anime_list->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FrameMain::wxListBox_anime_choosed ), NULL, this );
	wxButton_download->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::wxButton_download_click ), NULL, this );
}

FrameMain::~FrameMain()
{
	// Disconnect Events
	wxListBox_anime_list->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( FrameMain::wxListBox_anime_choosed ), NULL, this );
	wxButton_download->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FrameMain::wxButton_download_click ), NULL, this );

}
