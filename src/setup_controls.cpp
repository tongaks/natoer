#include "../headers/window.h"

struct Task {
	wxPanel* pnlTask;
	wxStaticText* lblTaskName; 
	wxBoxSizer* szrTaskPanel;

	Task(wxPanel* parent, std::string taskName) {
		this->pnlTask = new wxPanel(parent, wxID_ANY);
		pnlTask->SetBackgroundColour(wxColour(33, 34, 56));
		this->lblTaskName = new wxStaticText(this->pnlTask, wxID_ANY, taskName); 


		this->szrTaskPanel = new wxBoxSizer(wxHORIZONTAL);
		szrTaskPanel->Add(this->lblTaskName, 0, wxEXPAND | wxALL, 10);
		this->pnlTask->SetSizer(this->szrTaskPanel);

		parent->GetSizer()->Add(this->pnlTask, 0, wxEXPAND);
		parent->Layout();
	 }


};




void Window::SetupMenuBar() {
	menuBar = new wxMenuBar;
	menuItemFile = new wxMenu;
	menuItemFile->Append(ID_HIDE, wxT("Hide"));
	Bind(wxEVT_MENU, &Window::Minimize, this, ID_HIDE);

	menuItemFile->Append(wxID_ANY, wxT("New"));
	menuItemFile->Append(wxID_ANY, wxT("Open"));
	menuItemFile->Append(wxID_ANY, wxT("Save"));
	menuItemFile->Append(wxID_EXIT, wxT("&Quit"));
	Bind(wxEVT_MENU, [=](wxCommandEvent &ev){
		exit(0);
	}, NULL, wxID_EXIT);

	menuItemSettings = new wxMenu;
	menuItemSettings->Append(wxID_ANY, wxT("Themes"));
	menuItemSettings->Append(wxID_ANY, wxT("Preferences"));

	menuBar->Append(menuItemFile, wxT("&File"));
	menuBar->Append(menuItemSettings, wxT("Settings"));
	SetMenuBar(menuBar);
}


void Window::AddNewTask(wxCommandEvent &ev) {
	Task taskTemp(pnlTasks, "Task test 1");
}

void Window::Minimize(wxCommandEvent &ev) {
	menuBar->Hide();
	pnlNavbar->Hide();
	pnlTasks->Hide();
	SetClientSize(100, 100);
	GetSizer()->Layout();

	btnHide->Show();
	isMinimized = true;
}

void Window::UnMinimize(wxCommandEvent &ev) {
	menuBar->Show();
	pnlNavbar->Show();
	pnlTasks->Show();

	SetClientSize(windowX, windowY);
	GetSizer()->Layout();

	btnHide->Hide();
	isMinimized = false;
}