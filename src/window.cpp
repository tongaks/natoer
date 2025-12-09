#include "setup_controls.cpp"

Window::Window(const wxString &title, wxPoint wPoint, wxSize wSize)
: wxFrame(NULL, wxID_ANY, title, wPoint, wSize, wxBORDER_NONE) {
// : wxFrame(NULL, wxID_ANY, title, wPoint, wSize, wxCAPTION | wxCLOSE_BOX) {
	// Bind(wxEVT_CLOSE_WINDOW, &Window::OnClose, this);

	// panels
	pnlMain = new wxPanel(this, wxID_ANY, wxDP, wxSize(windowX, windowY));
	pnlNavbar = new wxPanel(this, wxID_ANY);
	pnlTasks = new wxPanel(this, wxID_ANY);
	pnlTasks->SetBackgroundColour(wxColour(70, 70, 70));


	// menu bar
	menuBar = new wxMenuBar;
	menuItemFile = new wxMenu;
	menuItemFile->Append(ID_HIDE, wxT("Hide"));
	Bind(wxEVT_MENU, &Window::Minimize, this, ID_HIDE);

	menuItemFile->Append(wxID_ANY, wxT("New"));
	menuItemFile->Append(wxID_ANY, wxT("Open"));
	menuItemFile->Append(wxID_ANY, wxT("Save"));
	menuItemFile->Append(wxID_EXIT, wxT("&Quit"));

	menuItemSettings = new wxMenu;
	menuItemSettings->Append(wxID_ANY, wxT("Themes"));
	menuItemSettings->Append(wxID_ANY, wxT("Preferences"));

	menuBar->Append(menuItemFile, wxT("&File"));
	menuBar->Append(menuItemSettings, wxT("Settings"));
	SetMenuBar(menuBar);

	
	// textboxs
	txtbxSearch = new wxTextCtrl(pnlNavbar, wxID_ANY);


	// buttons
	btnHide =  new wxButton(this, wxID_ANY, "View");
	btnHide->Bind(wxEVT_BUTTON, &Window::UnMinimize, this);
	btnHide->Hide();
	
	btnAddTask = new wxButton(pnlNavbar, wxID_ANY, "New");



	// sizers
	szrNavbar = new wxBoxSizer(wxHORIZONTAL);
	szrNavbar->Add(txtbxSearch, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);
	szrNavbar->Add(btnAddTask, 0, wxLEFT, 10);
	// szrNavbar->Add(btnHide, 0, wxLEFT | wxRIGHT, 10);
	pnlNavbar->SetSizer(szrNavbar);

	szrMainH = new wxBoxSizer(wxHORIZONTAL);
	szrMainH->Add(pnlNavbar, 1, wxEXPAND);

	szrMainV = new wxBoxSizer(wxVERTICAL);
	szrMainV->Add(szrMainH, 0, wxEXPAND | wxALL, 10);
	szrMainV->Add(pnlTasks, 1, wxEXPAND | wxALL, 13);
	SetSizer(szrMainV);
}
