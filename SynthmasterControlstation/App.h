#include "wx/wx.h"



class App : public wxApp {
public:
    bool OnInit() override;
    
};

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
    void OnQuit(wxCommandEvent& event);

private:
    DECLARE_EVENT_TABLE()

    
};
