#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include <iostream>
#include <wx/wx.h>
#include "../header/Game.h"
#include "../header/Card.h"
using namespace std;

class MAIN_Frame;
class BET_Frame;

class GAME_Frame : public wxFrame {
  public:
    GAME_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void user_information(int bet_money, int wallet_money);
    int money_betted;
    int money_wallet;

    void set_dealer_card();
    void set_player_card();
    int dealer_cards_counter;
    int player_cards_counter;
    

  private:
    BET_Frame* Bet_Window;
    MAIN_Frame* Menu_Window;
    
    Game *card_game;

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


  wxPanel *card_1_d;
  wxPanel *card_2_d;
  wxPanel *card_3_d;
  wxPanel *card_4_d;
  wxPanel *card_5_d;


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
  wxPanel *card_1;
  wxPanel *card_2;
  wxPanel *card_3;
  wxPanel *card_4;
  wxPanel *card_5;
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

    void dealer_final_stage();

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_RestartGame = 30,
    ID_returns = 69, 
    ID_hit_card = 70,
    ID_stay_card = 71
};

#endif /* GAMEFRAME_H_ */