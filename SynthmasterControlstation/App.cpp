#include "App.h"


IMPLEMENT_APP(App)

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
END_EVENT_TABLE()

bool App::OnInit() {

    MainFrame *frame = new MainFrame(wxT("SynthMaster 2.9 ControlStation"));
    frame->Show(true);

    return true;
}

//initializer list to define wxFrame:
MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxPoint(100, 100), wxDefaultSize, wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX) {

    wxMenuBar *menuBar = new wxMenuBar();

    wxMenu *aboutMenu = new wxMenu;
    aboutMenu->Append(wxID_ABOUT, wxT("Test"), 
                                wxT("More about this software"));

    menuBar->Append(aboutMenu, wxT("About"));    

    SetMenuBar(menuBar);


}

void MainFrame::OnQuit(wxCommandEvent& event) {
    Close();
}

DECLARE_APP(App)