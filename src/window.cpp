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
	SetupMenuBar();

	
	// textboxs
	txtbxSearch = new wxTextCtrl(pnlNavbar, wxID_ANY);


	// buttons
	btnHide =  new wxButton(this, wxID_ANY, "View");
	btnHide->Bind(wxEVT_BUTTON, &Window::UnMinimize, this);
	btnHide->Hide();
	
	btnAddTask = new wxButton(pnlNavbar, wxID_ANY, "New");
	btnAddTask->Bind(wxEVT_BUTTON, &Window::AddNewTask, this);



	// sizers
	szrNavbar = new wxBoxSizer(wxHORIZONTAL);
	szrNavbar->Add(txtbxSearch, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);
	szrNavbar->Add(btnAddTask, 0, wxLEFT, 10);
	pnlNavbar->SetSizer(szrNavbar);


	szrTasks = new wxBoxSizer(wxVERTICAL);
	// szrTasks->Add(pnlTask, 0, wxEXPAND);
	pnlTasks->SetSizer(szrTasks);


	// main sizers
	szrMainH = new wxBoxSizer(wxHORIZONTAL);
	szrMainH->Add(pnlNavbar, 1, wxEXPAND);

	szrMainV = new wxBoxSizer(wxVERTICAL);
	szrMainV->Add(szrMainH, 0, wxEXPAND | wxALL, 10);
	szrMainV->Add(pnlTasks, 1, wxEXPAND | wxALL, 13);
	SetSizer(szrMainV);
}
