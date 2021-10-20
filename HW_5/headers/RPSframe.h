#ifndef RPSFRAME_H_
#define RPSFRAME_H_

#include <wx/wx.h>

class Game;

class RPS_Frame: public wxFrame {
    public:
        RPS_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
        // RPS_Setup* getSetup_Game_Frame();
        int getPlayerMove();
        void resetPlayerMove();
        bool player_chose_RPS;

        void set_config(int rounds, int cpusMove);


    private:
        // RPS_Setup* Setup_Game_Frame;
        Game *RockPaperScissors;

        //menu on top bar
        void OnRestart(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
            
//////////// Game Set Up ////////////
        //Window setup
        wxBoxSizer* game_window;

        //title/subtitle
        wxStaticText *displayName;

        //round number
        wxStaticText *current_round;

        //round winner
        wxStaticText *round_winner;

/*Player*/
        //Player choice
        wxStaticText *Player_choice;

        //Player's Move
        int player_RPS_move;

        //Button set up for RPS
        wxBoxSizer* game_button_layout;
        wxButton* game_button_config;
        void OnClickRock(wxCommandEvent& event);
        void OnClickPaper(wxCommandEvent& event);
        void OnClickScissors(wxCommandEvent& event);

/*CPU*/
        //CPU player prediction
        wxStaticText *CPU_prediction;

        //CPU actual choice
        wxStaticText *CPU_choice;
/*Stats*/
        //CPU total wins
        wxStaticText *total_CPU_wins;

        //Player Total wins
        wxStaticText *total_Player_wins;

        //total ties between CPU and Player
        wxStaticText *total_ties;

/*Player made Move*/
        // bool player_chose_RPS;
        int RoundsChosen;
        int CPUchosen;

        wxDECLARE_EVENT_TABLE();
};

enum {
    ID_RestartGame = 4
};

enum RPS_buttons{
    buttonRock_ID = 101,
    buttonPaper_ID = 102,
    buttonScissors_ID = 103,
};

#endif /* RPSFRAME_H_ */
