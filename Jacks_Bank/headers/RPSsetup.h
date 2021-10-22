#ifndef RPSSETUP_H_
#define RPSSETUP_H_

#include <wx/wx.h>
#include <wx/slider.h> // slider 
#include <wx/tglbtn.h> // toggle button
#include "RPSframe.h"  // game

class RPS_Frame; //to not include class and cause infinite repetition

class RPS_Setup : public wxFrame {
  public:
    RPS_Setup(const wxString& title, const wxPoint& pos, const wxSize& size);
    
  private:
    RPS_Frame* RPS_Game_Frame;

    //menu on top bar
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);


////////////// SET UP //////////////////////
/*Window setup*/
    wxBoxSizer* window_layout;

/*Title*/
    wxStaticText *heading;

/*CPU Mode*/
    wxStaticText *CPUmode_display;
    int CPUMode;

/*button configuration*/
    wxBoxSizer* setup_box_config;
    wxButton* setup_button_config;
    void OnClick_RandCPU(wxCommandEvent& event);
    void OnClick_SmartCPU(wxCommandEvent& event);
    void OnClick_GeniusCPU(wxCommandEvent& event);

/* slider for amounf of rounds*/
    int fill;
    wxStaticText *roundNum;
    wxSlider *slider;
    void OnScroll(wxScrollEvent& event);

/*submit game settings button*/
    wxButton* submit_button_config;
    void OnClick_SubmitInfo(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

class Slider : public wxFrame {
    public:
        Slider(const wxString& title);
};

enum id_numbers{
    ID_SLIDER = 100,
    buttonSubmit_ID = 99,
};

enum CPU_mode{
  buttonRandCPU_ID = 105,
  buttonSmartCPU_ID = 106,
  buttonGeniusCPU_ID = 107,
};    

// const int ;

#endif /* RPSSETUP_H_ */