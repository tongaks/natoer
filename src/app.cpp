#include "../headers/app.h"
#include "../headers/window.h"

bool App::OnInit() {
    Window* window = new Window("test", wxPoint(40, 40), wxSize(windowX, windowY));
    window->Show(true);
    return true;
} wxIMPLEMENT_APP(App);