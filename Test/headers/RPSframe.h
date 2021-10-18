#ifndef RPSFRAME_H_
#define RPSFRAME_H_

#include <wx/wx.h>

class RPS_Frame: public wxFrame {
    public:
        RPS_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);

    private:
        //menu on top bar
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
            
        //Button set up for RPS
        wxBoxSizer* mainBox_config;
        wxButton* button_config;
        void OnClickRock(wxCommandEvent& event);
        void OnClickPaper(wxCommandEvent& event);
        void OnClickScissors(wxCommandEvent& event);


        wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Hello = 1
};

enum RPS_buttons{
    buttonRock_ID = 101,
    buttonPaper_ID = 102,
    buttonScissors_ID = 103,
};

#endif /* RPSFRAME_H_ */
