#ifndef RPSFRAME_H_
#define RPSFRAME_H_

<<<<<<< HEAD
#include <wx/wx.h>

class Game;

class MAIN_Frame;

class GAME_Frame: public wxFrame {
    public:
        GAME_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);

        //
        int getPlayerMove();
        void resetPlayerMove();
        bool player_chose_RPS;

        void set_config(int rounds, int CPUchosen);


    private:
        MAIN_Frame* Setup_Game_Frame;
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
        int round_counter;

        //round winner
        wxStaticText *round_winner;

/*Player*/
        //Player choice
        wxStaticText *Player_choice;

        //Button set up for RPS
        wxBoxSizer* game_button_layout;
        wxButton* game_button_config;
        void OnClickRock(wxCommandEvent& event);
        void OnClickPaper(wxCommandEvent& event);
        void OnClickScissors(wxCommandEvent& event);

        //executes each round
        void execute_match(int player_RPS_move);

        //Final pop up wiht game's winner and 2 options
        void Game_Over(wxCommandEvent& event);
        

/*CPU*/
        //CPU Mode Type
        wxStaticText *CPU_Opponent_Type;
        
        //CPU player prediction
        wxStaticText *CPU_prediction;

        //CPU actual choice
        wxStaticText *CPU_choice;
/*Stats*/
        //CPU total wins
        wxStaticText *total_CPU_wins;
=======

#include <wx/wx.h>
#include <string.h>
>>>>>>> e2cb63abf46e05763309d4b5164bfdc882d87930

using std::string;

class cGame : public wxFrame
{
public:
    cGame(const wxString& windowTitle);
    ~cGame();

<<<<<<< HEAD
/*Player made Move*/
        // bool player_chose_RPS;
        int RoundsChosen;

        //helper function to determine winner
        void calculateFinalWinner(int cpu_wins, int player_wins);
        
        //variables to keep track of game
        wxString champion;
        wxDECLARE_EVENT_TABLE();
};

enum id_nums{
    ID_RestartGame = 4
};
=======
    void config_game(int rounds, int cpuChoice);

private:
    
>>>>>>> e2cb63abf46e05763309d4b5164bfdc882d87930

};

#endif /* RPSFRAME_H_ */
