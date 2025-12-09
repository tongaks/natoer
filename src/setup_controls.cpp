#include "../headers/window.h"

void Window::Minimize(wxCommandEvent &ev) {
	menuBar->Hide();
	pnlNavbar->Hide();
	pnlTasks->Hide();
	SetClientSize(100, 100);
	GetSizer()->Layout();

	isMinimized = true;
}

void Window::UnMinimize(wxCommandEvent &ev) {
	menuBar->Show();
	pnlNavbar->Show();
	pnlTasks->Show();
	btnHide->Hide();

	SetClientSize(windowX, windowY);
	GetSizer()->Layout();

	isMinimized = false;
}