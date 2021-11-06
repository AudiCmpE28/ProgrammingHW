#include <iostream>
#include <wx/wx.h>
#include "headers/RPSframe.h"
#include "headers/RPSsetup.h" //other class

#include "headers/Game.h"

using namespace std;

//Rock Button
//Paper Button
//Scissors Button

wxBEGIN_EVENT_TABLE(GAME_Frame, wxFrame)
    EVT_MENU(ID_RestartGame, GAME_Frame::OnRestart)
    EVT_MENU(wxID_ABOUT, GAME_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, GAME_Frame::OnExit)

    EVT_BUTTON(buttonRock_ID, GAME_Frame::OnClickRock)
    EVT_BUTTON(buttonPaper_ID, GAME_Frame::OnClickPaper)
    EVT_BUTTON(buttonScissors_ID, GAME_Frame::OnClickScissors)

    // EVT_SLIDER(ID_SLIDER, GAME_Frame::OnScroll)
wxEND_EVENT_TABLE()

GAME_Frame::GAME_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
/*Top Bar Menu*/
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_RestartGame, "&Restart...\tCtrl-H", "Restart Game!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Quit the Game");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT, "&About...\tCtrl-P", "Game Instructions!");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("For Game Info, go to 'Help->About' or 'Ctrl-P'");

/*Play Game*/
    //window layout for game
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    game_window = new wxBoxSizer(wxVERTICAL); //items placed vertical
    game_window->AddSpacer(20);

    //title of game
    wxFont game_title(15, wxDEFAULT, wxNORMAL, wxBOLD);
    displayName = new wxStaticText(this, wxID_ANY, wxT("Rock | Paper | Scissors!"), wxPoint(50, 15));
    displayName->SetFont(game_title);
    game_window->Add(displayName, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(10);

    //round number
    wxFont round_title(11, wxDEFAULT, wxNORMAL, wxDEFAULT);
    current_round = new wxStaticText(this, wxID_ANY, wxT("Round: 1"), wxPoint(50, 15));
    current_round->SetFont(round_title);
    game_window->Add(current_round, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(10);

    //Round Winner
    wxFont winner_title(11, wxDEFAULT, wxNORMAL, wxDEFAULT);
    round_winner = new wxStaticText(this, wxID_ANY, wxT("Winner: Play to Win"), wxPoint(50, 15));
    round_winner->SetFont(winner_title);
    game_window->Add(round_winner, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(40);

/*Choose Rock or Paper or Scissors*/
    //bplayer label
    wxFont user_spot(12, wxDEFAULT, wxNORMAL, wxBOLD);
    displayName = new wxStaticText(this, wxID_ANY, wxT("Your Options"), wxPoint(50, 15));
    displayName->SetFont(user_spot);
    game_window->Add(displayName, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(10);

    //RPS game buttons
    game_button_layout = new wxBoxSizer(wxHORIZONTAL);

    wxFont user_choose(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    displayName = new wxStaticText(this, wxID_ANY, wxT("Choose:"), wxPoint(50, 15));
    displayName->SetFont(user_choose);
    game_button_layout->Add(displayName, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion

    game_button_config = new wxButton(this, buttonRock_ID, _T("Rock"), wxDefaultPosition, wxDefaultSize, 0);
    game_button_layout->Add(game_button_config, 0, wxALL, 5);

    game_button_config = new wxButton(this, buttonPaper_ID, _T("Paper"), wxDefaultPosition, wxDefaultSize, 0);
    game_button_layout->Add(game_button_config, 0, wxALL, 5);

    game_button_config = new wxButton(this, buttonScissors_ID, _T("Scissors"), wxDefaultPosition, wxDefaultSize, 0);
    game_button_layout->Add(game_button_config, 0, wxALL, 5);

    game_window->Add(game_button_layout, 0, wxALIGN_CENTER, 10);
    game_window->AddSpacer(20);

    //players choice
    wxFont display_players_move(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    Player_choice = new wxStaticText(this, wxID_ANY, wxT("Player's Move: Choose"), wxPoint(50, 15));
    Player_choice->SetFont(display_players_move);
    game_window->Add(Player_choice, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(40);

/*CPU Data*/
    //CPU label
    wxFont cpu_label(12, wxDEFAULT, wxNORMAL, wxBOLD);
    CPU_Opponent_Type = new wxStaticText(this, wxID_ANY, wxT("Modes Computer"), wxPoint(50, 15));
    CPU_Opponent_Type->SetFont(cpu_label);
    game_window->Add(CPU_Opponent_Type, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(20);

    //CPU Predcition
    wxFont display_predcition(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    CPU_prediction = new wxStaticText(this, wxID_ANY, wxT("CPU predicted Player Move To Be: N/A"), wxPoint(50, 15));
    CPU_prediction->SetFont(display_predcition);
    game_window->Add(CPU_prediction, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(10);

    //CPU Chosen decision
    wxFont display_cpu_choice(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    CPU_choice = new wxStaticText(this, wxID_ANY, wxT("Computer's Move: N/A"), wxPoint(50, 15));
    CPU_choice->SetFont(display_cpu_choice);
    game_window->Add(CPU_choice, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(40);

/*Display Totals*/
    //stats title
    wxFont stats(12, wxDEFAULT, wxNORMAL, wxBOLD);
    displayName = new wxStaticText(this, wxID_ANY, wxT("Scoreboard"), wxPoint(50, 15));
    displayName->SetFont(stats);
    game_window->Add(displayName, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(20);

    //Display Total CPU wins
    wxFont cpu_total(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    total_CPU_wins = new wxStaticText(this, wxID_ANY, wxT("CPU Wins: 0"), wxPoint(50, 15)); // initial message
    total_CPU_wins->SetFont(cpu_total);
    game_window->Add(total_CPU_wins, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(10);

    //Display Total Player wins
    wxFont player_total(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    total_Player_wins = new wxStaticText(this, wxID_ANY, wxT("Player Wins: 0"), wxPoint(50, 15)); // initial message
    total_Player_wins->SetFont(player_total);
    game_window->Add(total_Player_wins, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(10);

    //total_ties
    wxFont display_ties(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    total_ties = new wxStaticText(this, wxID_ANY, wxT("Total Ties: 0"), wxPoint(50, 15)); // initial message
    total_ties->SetFont(display_ties);
    game_window->Add(total_ties, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    game_window->AddSpacer(20);

/* finalize window layout*/
    this->SetSizer(game_window);
    this->Layout();

/*Variables Initial Values*/
    round_counter = 1;
}

/*Top Bar Menu*/
void GAME_Frame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("Welcome to Rock, Paper, Scissors!\n"
                 "\nThe game is simple, pick rock, paper, or scissors by entering a number between 1 to 3."
                 "\n\nThere are only 3 rules to win or lose: "
                 "\n\t1) Paper beats Rock"
                 "\n\t2) Scissors beats paper"
                 "\n\t3) Rock beats Scissors",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void GAME_Frame::OnRestart(wxCommandEvent &event){
    Setup_Game_Frame = new MAIN_Frame("Re-configuration", wxPoint(50, 50), wxSize(450, 640));
    Setup_Game_Frame->Center();
    Setup_Game_Frame->Show(true);

    Close(true);
}

void GAME_Frame::OnExit(wxCommandEvent &event) {
    cout << "OnExit: Exiting Gaming app!" << endl;
    Close(true);
}

/*Play*/
void GAME_Frame::OnClickRock(wxCommandEvent &event)
{
    Player_choice->SetLabel("Player's Move: Rock");
    execute_match(1);
}

void GAME_Frame::OnClickPaper(wxCommandEvent &event)
{
    Player_choice->SetLabel("Player's Move: Paper");
    execute_match(2);
}

void GAME_Frame::OnClickScissors(wxCommandEvent &event)
{
    Player_choice->SetLabel("Player's Move: Scissors");
    execute_match(3);
}

string NtoMove(int move)
{
    string retValue;
    if (move == 1)
        retValue = "Rock";
    else if (move == 2)
        retValue = "Paper";
    else if (move == 3)
        retValue = "Scissors";

    return retValue;
}

string NtoWinner(int winner)
{
    string retValue;
    if (winner == 1)
        retValue = "Player Wins!";
    else if (winner == 2)
        retValue = "CPU Wins!";
    else if (winner == -1)
        retValue = "Tie!";

    return retValue;
}

void GAME_Frame::calculateFinalWinner(int cpu_wins, int player_wins) {
    if (cpu_wins > player_wins) {
        champion = "Game Champion: Computer";
    } else if (cpu_wins < player_wins) {
        champion = "Game Champion: Player";
    } else {
        champion = "Game Champion: No-One";
    }
}




void GAME_Frame::execute_match(int player_RPS_move) {
    //while within round amount
    if (round_counter <= RoundsChosen) {
        GameStats game_info = RockPaperScissors->executeMatch(player_RPS_move);

        current_round->SetLabel(wxString::Format(wxT("Round: %i"), round_counter));       
        round_counter++;
        round_winner->SetLabel(wxString::Format(wxT("Winner: %s"), NtoWinner(game_info.Round_Winner)));
        if (game_info.CPU_prediction != 0) {
            CPU_prediction->SetLabel(wxString::Format(wxT("CPU predicted Player Move To Be: %s"), NtoMove(game_info.CPU_prediction)));
        }
        CPU_choice->SetLabel(wxString::Format(wxT("Computer's Move: %s"), NtoMove(game_info.CPU_move)));

        total_CPU_wins->SetLabel(wxString::Format(wxT("CPU Wins: %i"), game_info.CPU_wins));
        total_Player_wins->SetLabel(wxString::Format(wxT("Player Wins: %i"), game_info.Player_wins));
        total_ties->SetLabel(wxString::Format(wxT("Total Ties: %i"), game_info.total_ties));
        calculateFinalWinner(game_info.CPU_wins, game_info.Player_wins);
    
    }
    if(round_counter > RoundsChosen){ //if game is over, lock the game   
        wxCommandEvent unusedEvent; //Event for temporary use 
        this->Game_Over(unusedEvent);     
    }
}

void GAME_Frame::Game_Over(wxCommandEvent &event){
        wxMessageDialog *dial = new wxMessageDialog(NULL, champion, "Game Over", wxOK | wxCANCEL | wxCANCEL_DEFAULT| wxICON_AUTH_NEEDED);
        dial->SetOKCancelLabels("Restart Game", "Quit Game"); // change Ok and Cancel Button names respectfully
        
        int buttonPressed = dial->ShowModal();// displays message box everytime its called
        
        if(buttonPressed == wxID_OK){ //linked to restarting game
            this->OnRestart(event);
        }else if(buttonPressed == wxID_CANCEL){ //linked to exiting game
            this->OnExit(event);
        }

        RockPaperScissors->update_text_file();
}

void GAME_Frame::set_config(int rounds, int CPUchosen) {
    if (CPUchosen == 1) {
        CPU_Opponent_Type->SetLabel("Random Computer");
    }else if (CPUchosen == 2) {
        CPU_Opponent_Type->SetLabel("Smart Computer");
    }else{
        CPU_Opponent_Type->SetLabel("Genius Computer");
    }

    RoundsChosen = rounds;

    RockPaperScissors = new Game();
    RockPaperScissors->executeSetup(CPUchosen);
}
