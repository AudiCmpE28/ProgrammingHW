#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include <iostream>
#include <wx/wx.h>
using namespace std;

class MAIN_Frame;
class BET_Frame;

class GAME_Frame : public wxFrame {
  public:
    GAME_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void user_information(int bet_money, int wallet_money);
    int money_betted;
    int money_wallet;
    

  private:
    bool played_round;
    BET_Frame* Bet_Window;
    MAIN_Frame* Menu_Window;
    
    //menu on top bar
    void OnRestart(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    /*Window setup*/
    wxBoxSizer* window_layout;

    /*Title*/
    wxStaticText *heading;


    /*Money that was Bet*/
    wxStaticText *Bet_Money;
    wxBoxSizer *display_bet;

/*Dealer*/


/*Score*/
    wxBoxSizer *scores;
    wxStaticText *Player_Score;
    wxStaticText *CPU_Score;
    
/*Player*/
    /*Buttons*/
    wxBoxSizer* button_config;
    wxButton* setup_button_config;

    /*Hit button*/
    void OnClick_Hit(wxCommandEvent& event);

    /*Stay button*/
    void OnClick_Stay(wxCommandEvent& event);

    /*Return button*/
    void OnClick_Return(wxCommandEvent& event);


    wxDECLARE_EVENT_TABLE();
};

enum id_nums{
    ID_RestartGame = 30,
    ID_returns = 69, 
    ID_hit_card = 70,
    ID_stay_card = 71
};

#endif /* GAMEFRAME_H_ */