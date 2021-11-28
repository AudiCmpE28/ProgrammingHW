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


  wxPanel *card_1;
  wxPanel *card_2;
  wxPanel *card_3;
  wxPanel *card_4;
  wxPanel *card_5;


/*Dealer*/
  wxStaticText *card_1_info_dealer;
  wxStaticText *card_2_info_dealer;
  wxStaticText *card_3_info_dealer;
  wxStaticText *card_4_info_dealer;
  wxStaticText *card_5_info_dealer;




/*Score*/
    wxBoxSizer *scores;
    wxStaticText *Player_Score;
    wxStaticText *CPU_Score;
    
/*Player*/
  wxStaticText *card_1_info_player;
  wxStaticText *card_2_info_player;
  wxStaticText *card_3_info_player;
  wxStaticText *card_4_info_player;
  wxStaticText *card_5_info_player;


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