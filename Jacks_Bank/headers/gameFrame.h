#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include <iostream>
#include <wx/wx.h>
#include "../header/Game.h"
#include "../header/Card.h"
using namespace std;

//we declare classes since they exist,. but we do not include
//classes header files here, else will create an infinite
//loop since all frames are essentially connected to call
//eachother
class MAIN_Frame;
class BET_Frame;

class GAME_Frame : public wxFrame, Observer {
  public:
    //constructor that can be called from other frames to be created
    GAME_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    vector<Card> dealerHand;
    vector<Card> playerHand;
    
    void update(vector<Card> playerH, vector<Card> dealerH);
    void initialize_game(int bet_money);
    void set_dealer_card();
    void set_player_card();
    

  private:
    //pointers allow us to use variable as an empty placeholder, maybe
    //we dont need pointers but use it. This will alow us to
    //create new window frame when we wanna switch windows 
    //without creating infinite loop that breaks code.
    //NOTE: do include header file in .cpp file NOT .h aka here
    BET_Frame* Bet_Window;
    MAIN_Frame* Menu_Window;
    
    Game *card_game; //this class is fine to include in .h
                    //since its only used here and does not call other windows
                    //main issue is between frames (in our case)

    //menu on top bar
    void OnRestart(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    /*Window setup*/
    wxBoxSizer* window_layout; //not necessary here but yolo

    /*Title*/
    wxStaticText *heading; //used to display, we can modify in functiosn


    /*Money that was Bet*/
    wxStaticText *Bet_Money;
    wxBoxSizer *display_bet;


  wxPanel *card_1_d;//can be modified iun fcuntoin
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

    wxDECLARE_EVENT_TABLE(); //set table
};

//GUI buttons and so are ID driven since we use ID to link
// button with function, but there is longer ways to not have
//to use IDS, and event table is NOT the only way to link the ID's
enum {
    ID_RestartGame = 30,
    ID_returns = 69, 
    ID_hit_card = 70,
    ID_stay_card = 71
};

#endif /* GAMEFRAME_H_ */