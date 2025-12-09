#include "../headers/window.h"

Window::Window(const wxString &title, wxPoint wPoint, wxSize wSize)
: wxFrame(NULL, wxID_ANY, title, wPoint, wSize, wxCAPTION | wxCLOSE_BOX) {
	// Bind(wxEVT_CLOSE_WINDOW, &Window::OnClose, this);

	// panels
	pnlMain = new wxPanel(this, wxID_ANY, wxDP, wxSize(windowX, windowY));
	pnlNavbar = new wxPanel(this, wxID_ANY);
	pnlTasks = new wxPanel(this, wxID_ANY);
	pnlTasks->SetBackgroundColour(wxColour(70, 70, 70));


	// menu bar
	menuBar = new wxMenuBar;
	menuItemFile = new wxMenu;
	menuItemFile->Append(wxID_ANY, wxT("New"));
	menuItemFile->Append(wxID_ANY, wxT("Open"));
	menuItemFile->Append(wxID_ANY, wxT("Save"));
	menuItemFile->Append(wxID_EXIT, wxT("&Quit"));

	menuBar->Append(menuItemFile, wxT("&File"));
	SetMenuBar(menuBar);

	
	// textboxs
	txtbxSearch = new wxTextCtrl(pnlNavbar, wxID_ANY);


	// buttons
	btnHide = new wxButton(pnlNavbar, wxID_ANY, "Hide");
	btnAddTask = new wxButton(pnlNavbar, wxID_ANY, "New");



	// sizers
	szrNavbar = new wxBoxSizer(wxHORIZONTAL);
	szrNavbar->Add(txtbxSearch, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);
	szrNavbar->Add(btnAddTask, 0, wxLEFT, 10);
	szrNavbar->Add(btnHide, 0, wxLEFT | wxRIGHT, 10);
	pnlNavbar->SetSizer(szrNavbar);

	szrMainH = new wxBoxSizer(wxHORIZONTAL);
	szrMainH->Add(pnlNavbar, 1, wxEXPAND);

	szrMainV = new wxBoxSizer(wxVERTICAL);
	szrMainV->Add(szrMainH, 0, wxEXPAND | wxALL, 10);
	szrMainV->Add(pnlTasks, 1, wxEXPAND | wxALL, 13);
	SetSizer(szrMainV);
}
