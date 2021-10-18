#ifndef RPSSETUP_H_
#define RPSSETUP_H_

#include <wx/wx.h>
#include <wx/slider.h>

class RPS_Setup : public wxFrame {
  public:
    RPS_Setup(const wxString& title, const wxPoint& pos, const wxSize& size);

  private:
      //menu on top bar
      void OnHello(wxCommandEvent& event);
      void OnExit(wxCommandEvent& event);
      void OnAbout(wxCommandEvent& event);


    ////////////// SET UP //////////////////////
      //Window setup
      wxBoxSizer* window_layout;

      //Title
      wxStaticText *heading;

      //button configuration
      wxBoxSizer* setup_box_config;
      wxButton* setup_button_config;
      void OnClick_RandCPU(wxCommandEvent& event);
      void OnClick_SmartCPU(wxCommandEvent& event);
      void OnClick_GeniusCPU(wxCommandEvent& event);

      // slider
      void OnScroll(wxScrollEvent& event);
      wxSlider *slider;
      int fill;
      wxString round_amount;

      wxDECLARE_EVENT_TABLE();
};

class Slider : public wxFrame {
    public:
        Slider(const wxString& title);
};

enum {
    ID_Hello2 = 10,
    ID_SLIDER = 100,
};

enum CPU_mode{
  buttonRandCPU_ID = 105,
  buttonSmartCPU_ID = 106,
  buttonGeniusCPU_ID = 107,
};    

// const int ;

#endif /* RPSSETUP_H_ */