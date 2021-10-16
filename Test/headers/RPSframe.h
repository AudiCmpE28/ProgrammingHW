#ifndef RPSFRAME_H_
#define RPSFRAME_H_

#include <wx/wx.h>
#include <wx/slider.h>

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

        // slider
        void OnScroll(wxScrollEvent& event);
        wxSlider *slider;
        int fill;
        
        wxDECLARE_EVENT_TABLE();
};

class Slider : public wxFrame {
    public:
        Slider(const wxString& title);
};


enum {
    ID_Hello    = 1
};

enum RPS_button{
    button1 = 1,
    button2 = 2,
    button3 = 3
};
const int ID_SLIDER = 100;

#endif /* RPSFRAME_H_ */
