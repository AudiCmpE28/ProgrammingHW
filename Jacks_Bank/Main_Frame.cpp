#include "wx/sizer.h"

#include "headers/mainFrame.h" //main class
#include "headers/betFrame.h" //other class
#include "headers/bankFrame.h" //other class
using namespace std;

Player mainPlayer;

/* ID's for Menu and Buttons */
wxBEGIN_EVENT_TABLE(MAIN_Frame, wxFrame)
    // EVT_MENU(wxID_EXIT, MAIN_Frame::OnRestart)
    EVT_MENU(wxID_ABOUT, MAIN_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, MAIN_Frame::OnExit) 

    EVT_BUTTON(ID_game_button, MAIN_Frame::OnClick_Game_Window)   
    EVT_BUTTON(ID_bank_button, MAIN_Frame::OnClick_Bank_Window) 
wxEND_EVENT_TABLE()


MAIN_Frame::MAIN_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size){
/*Menu Top Bar*/
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Quit the Game");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT, "&About...\tCtrl-P", "Game Instructions!");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("For Game Info, go to 'Help->About' or 'Ctrl-P'");

/* SET UP */
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    window_layout = new wxBoxSizer(wxVERTICAL); //items placed vertical

    //Title
    window_layout->AddSpacer(20);
    wxFont title_font(17, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Jack's Bank"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);

    // Instructions
    wxFont game_mode_font(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    string game_mode = "# Welcome to Jack's Bank #\n"
                        "\nFor game information, go to:"
                        "\n\t   Help -> About" 
                        "\n\t\t   or"
                        "\n\t        Ctrl-P";
    
    heading = new wxStaticText(this, wxID_ANY, game_mode, wxPoint(50, 15));
    heading->SetFont(game_mode_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(45);

/* Wallet Balance */
    Wallet_Display = new wxBoxSizer(wxHORIZONTAL); 

    wxFont wallet_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Wallet Amount: "), wxPoint(50, 15));
    heading->SetFont(wallet_font);
    Wallet_Display->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion

    string LwalletBalance = "$" + to_string(mainPlayer.getWallet());
    wxFont wallet_heading(14, wxDEFAULT, wxNORMAL, wxDEFAULT);
    wallet = new wxStaticText(this, wxID_ANY, wxT(walletBalance), wxPoint(30, 15));
    wallet->SetFont(wallet_heading);
    Wallet_Display->Add(wallet, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    window_layout->Add(Wallet_Display, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(40);


/* Route to Next Window */
    // window_layout->AddSpacer(290);
    window_layout->AddSpacer(110);
    //button Layout
    window_box_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    window_button_config = new wxButton(this, ID_game_button, _T("Game Window"), wxDefaultPosition, wxDefaultSize, 0);
    window_box_config->Add(window_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom

    window_box_config->AddSpacer(90);
    window_button_config = new wxButton(this, ID_bank_button, _T("Bank Window"), wxDefaultPosition, wxDefaultSize, 0);
    window_box_config->Add(window_button_config, 0, wxALL, 5);

    window_layout->Add(window_box_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(10);

/* Finalize layout */
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

/* Variables Initialized */
    mode_selected = -1;
    money_in_Wallet = mainPlayer.getWallet();
}

void MAIN_Frame::OnAbout(wxCommandEvent &event){
    wxMessageBox("# Welcome to Jack's Bank #\n"
                    "\nYou will have a wallet that represents money you have"
                    "\ninstant access to use. If you desire to save money,"
                    "\nyou can access the bank where you may also retrieve"
                    "\nmoney. To make money, you can head to the game window"
                    "\nto play Jack Black, where you can bet any amount of money"
                    "\nyou own, with potential to lose bet amount or win twice"
                    "\ntwice as much. Game ends when you lose all money or you"
                    "\nor you choose to restart",
                 "About Jacks Bank",wxOK | wxICON_INFORMATION);
}

void MAIN_Frame::OnExit(wxCommandEvent &event){
    cout << "OnExit: Exiting Jack's Bank app!" << endl;
    Close(true);
}



void MAIN_Frame::wallet_updated(){
    money_in_Wallet = mainPlayer.getWallet();
    wallet->SetLabel(wxString::Format(wxT("$%i"), money_in_Wallet));
}



/* Next Window Buttons */
void MAIN_Frame::OnClick_Game_Window(wxCommandEvent& event){
    Game_Window = new BET_Frame("", wxPoint(50, 50), wxSize(450, 640));
    Game_Window->Center();
    Game_Window->Show(true);

    Close(true);

}

void MAIN_Frame::OnClick_Bank_Window(wxCommandEvent& event){
    Bank_Window = new BANK_Frame("", wxPoint(50, 50), wxSize(450, 640));
    Bank_Window->Center();
    Bank_Window->Show(true);
    Bank_Window->wallet_money_updated();

    Close(true);
        
}

//need a button to return to main screen
