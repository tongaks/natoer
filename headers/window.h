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

	// menu bar
	wxMenuBar* menuBar;
	wxMenu* menuItemFile;

	// panels
	wxPanel* pnlMain;
	wxPanel* pnlTasks;
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
	bool isMinimized = false;


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