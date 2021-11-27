#ifndef BETFRAME_H_
#define BETFRAME_H_

#include <wx/wx.h>
// #include "RPSmain.h"

class GAME_Frame; //to not include class and cause infinite repetition
class MAIN_Frame;

class BET_Frame : public wxFrame {
  public:
    BET_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void set_wallet_money(int money);
    int wallet_money;
    int wallet_backup;

  private:
  
    GAME_Frame* Game_Window;
    MAIN_Frame* Menu_Window;

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

/**/
    /*Money that in Wallet*/
    wxStaticText *Wallet_Money;
    wxBoxSizer *display_wallet;


/* slider for amounf of rounds*/
    int fill;
    wxStaticText *roundNum;
    wxSlider *slider;
    void OnScroll(wxScrollEvent& event);


/*button configuration*/
    wxBoxSizer* setup_box_config;
/*submit game settings button*/
    wxButton* button_config;
    void OnClick_Back_Menu(wxCommandEvent& event);
    void OnClick_SubmitInfo(wxCommandEvent& event);
    

    wxDECLARE_EVENT_TABLE();
};

class Slider : public wxFrame {
    public:
        Slider(const wxString& title);
};

enum id_bet_numbers{
    ID_SLIDER = 95,
    ID_backMenu = 98,
    buttonSubmitBet_ID = 99,
};


// const int ;

#endif /* BETFRAME_H_ */