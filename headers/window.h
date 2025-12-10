#pragma once

#include <iostream>
#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <string.h>


const auto wxDP = wxDefaultPosition;
const auto wxDS = wxDefaultSize;
const int windowX = 500;
const int windowY = 600;

class Window : public wxFrame {
	const int ID_HIDE = 128;
	bool isHidden = false;

	// menu bar
	wxMenuBar* menuBar;
	wxMenu* menuItemFile;
	wxMenu* menuItemEdit;
	wxMenu* menuItemSettings;

	// panels
	wxPanel* pnlMain;
	wxPanel* pnlNavbar;


	// sizers
	wxBoxSizer* szrMainH;
	wxBoxSizer* szrMainV;
	wxBoxSizer* szrNavbar;
	wxBoxSizer* szrTasks;


	// textbox
	wxTextCtrl* txtbxSearch;


	// buttons
	wxButton* btnHide;
	wxButton* btnAddTask;


public:
	Window(const wxString &title, wxPoint wPoint, wxSize wSize);

	wxPanel* pnlTasks;
	bool isMinimized = false;


	// event handlers
	void Minimize(wxCommandEvent &ev);
	void UnMinimize(wxCommandEvent &ev);
	void AddNewTask(wxCommandEvent &ev);



	// setup
	void SetupMenuBar();








	// void Minimize(wxCommandEvent &ev) {
	// 	Fit();
	// 	Layout();

	// 	long style = GetWindowStyleFlag();
	// 	style |= wxSTAY_ON_TOP;

	// 	SetWindowStyleFlag(style);
	// 	Raise();

	// 	btn_test->SetLabel("View");
	// 	isMinimized = true;
	// }

	// void UnMinimize(wxCommandEvent &ev) {
	// 	SetClientSize(500, 600);

	// 	long style = GetWindowStyleFlag();
	// 	style &= ~wxSTAY_ON_TOP;
	// 	SetWindowStyleFlag(style);
	// 	Raise();

	// 	btn_test->SetLabel("Hide");
	// 	isMinimized = false;
	// }
};