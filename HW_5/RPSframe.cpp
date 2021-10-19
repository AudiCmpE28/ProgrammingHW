#include <iostream>
#include <wx/wx.h>
#include "headers/RPSframe.h"
#include "headers/RPSsetup.h" //other class

using namespace std;

 //Rock Button
 //Paper Button
 //Scissors Button

wxBEGIN_EVENT_TABLE(RPS_Frame, wxFrame)
    EVT_MENU(ID_RestartGame, RPS_Frame::OnRestart)
    EVT_MENU(wxID_ABOUT, RPS_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, RPS_Frame::OnExit)

    EVT_BUTTON(buttonRock_ID, RPS_Frame::OnClickRock)
    EVT_BUTTON(buttonPaper_ID, RPS_Frame::OnClickPaper)
    EVT_BUTTON(buttonScissors_ID, RPS_Frame::OnClickScissors)

    // EVT_SLIDER(ID_SLIDER, RPS_Frame::OnScroll)
wxEND_EVENT_TABLE()



RPS_Frame::RPS_Frame(const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame(NULL, wxID_ANY, title, pos, size) {

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_RestartGame, "&Restart...\tCtrl-H", "Restart Game!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Quit the Game");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to RPS!      For Game Info, go to Help -> About");


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
    displayName = new wxStaticText(this, wxID_ANY, wxT("Computer"), wxPoint(50, 15));
    displayName->SetFont(cpu_label);
    game_window->Add(displayName, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
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
    current_round = new wxStaticText(this, wxID_ANY, wxT("Scoreboard"), wxPoint(50, 15));
    current_round->SetFont(stats);
    game_window->Add(current_round, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
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
}


/*Top Bar Menu*/
void RPS_Frame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Welcome to Rock, Paper, Scissors!\n" 
                 "\nThe game is simple, pick rock, paper, or scissors by entering a number between 1 to 3."
                 "\n\nThere are only 3 rules to win or lose: "
                 "\n\t1) Paper beats Rock" 
                 "\n\t2) Scissors beats paper" 
                 "\n\t3) Rock bears Scissors", 
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void RPS_Frame::OnRestart(wxCommandEvent& event){
    Setup_Game_Frame = new RPS_Setup("Rock-Paper-Scissors-configure", wxPoint(50, 50), wxSize(450, 640));
    Setup_Game_Frame->Center();
    Setup_Game_Frame->Show(true);

    Destroy();
}

void RPS_Frame::OnExit(wxCommandEvent& event) {
    cout << "OnExit: Exiting Rock-Paper-Scissors app!" << endl;
    Close(true);
}


/*Play*/
void RPS_Frame::OnClickRock(wxCommandEvent& event) {
    // // wxString msg = _T("Hello World");
    // // wxString info = _T("linux-buddy");
    // wxMessageBox("Rock!", "Rock Button", wxOK | wxICON_INFORMATION, this);
    Player_choice->SetLabel("Player's Move: Rock");
}

void RPS_Frame::OnClickPaper(wxCommandEvent& event) {
    // wxMessageBox("Paper!", "Paper Button", wxOK | wxICON_INFORMATION, this);
    Player_choice->SetLabel("Player's Move: Paper");
}

void RPS_Frame::OnClickScissors(wxCommandEvent& event) {
    // wxMessageBox("Scissors!", "Scissors Button", wxOK | wxICON_INFORMATION, this);
    Player_choice->SetLabel("Player's Move: Scissors");
}
