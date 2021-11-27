#include <wx/wx.h>

#include <iostream>
#include "headers/gameFrame.h" //main class

using namespace std;

wxBEGIN_EVENT_TABLE(GAME_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, GAME_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, GAME_Frame::OnExit)

    EVT_BUTTON(ID_returns, GAME_Frame::OnClick_Hit)
    EVT_BUTTON(ID_hit_card, GAME_Frame::OnClick_Stay)
    EVT_BUTTON(ID_stay_card, GAME_Frame::OnClick_Return)
wxEND_EVENT_TABLE()

GAME_Frame::GAME_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
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
    // window_layout->AddSpacer(20);
    // wxFont title_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    // heading = new wxStaticText(this, wxID_ANY, wxT("Jack Black"), wxPoint(50, 15));
    // heading->SetFont(title_font);
    // window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    // window_layout->AddSpacer(20);


/*Money Bet*/
    display_bet = new wxBoxSizer(wxHORIZONTAL); 

    wxFont wallet_font(12, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Bet Money: "), wxPoint(50, 15));
    heading->SetFont(wallet_font);
    display_bet->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    wxFont Bet_Money_heading(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    Bet_Money = new wxStaticText(this, wxID_ANY, wxT("$0.00"), wxPoint(30, 15));
    Bet_Money->SetFont(Bet_Money_heading);
    display_bet->Add(Bet_Money, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    window_layout->Add(display_bet, 0, wxALIGN_RIGHT, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);


/*Dealer*/
    wxFont dealer_title_font(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Dealer"), wxPoint(50, 15));
    heading->SetFont(dealer_title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);



    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Windows_7_logo.png", wxBITMAP_TYPE_PNG), wxPoint(50,100), wxSize(100, 500));
    window_layout->AddSpacer(20);



/*Score*/
    wxFont top_row_line(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("===================================="), wxPoint(50, 15));
    heading->SetFont(top_row_line);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);


    wxFont scores_display(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("[Player]        [Dealer]"), wxPoint(50, 15));
    heading->SetFont(scores_display);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);


    scores = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    wxFont player_display(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    Player_Score = new wxStaticText(this, wxID_ANY, wxT("[0]"), wxPoint(50, 15));
    Player_Score->SetFont(player_display);
    scores->Add(Player_Score, 0, wxALIGN_CENTER, 10); 

    scores->AddSpacer(120);

    wxFont dealer_display(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    CPU_Score = new wxStaticText(this, wxID_ANY, wxT("[0]"), wxPoint(50, 15));
    CPU_Score->SetFont(dealer_display);
    scores->Add(CPU_Score, 0, wxALIGN_CENTER, 10); 

    window_layout->Add(scores, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(40);


    wxFont bottom_row_line(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("===================================="), wxPoint(50, 15));
    heading->SetFont(bottom_row_line);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(15);


/*Player*/
    wxFont player_title_font(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Player"), wxPoint(50, 15));
    heading->SetFont(player_title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);
    
    window_layout->AddSpacer(20);



/*Buttons*/
    /* Hit Button Layout */
    button_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    setup_button_config = new wxButton(this, ID_hit_card, _T("HIT"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom
    button_config->AddSpacer(40); //space between them

    /*Stay Button Layout*/
    setup_button_config = new wxButton(this, ID_stay_card, _T("STAY"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5);
    window_layout->Add(button_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(60);



    /* Return Button */
    setup_button_config = new wxButton(this, ID_returns, _T("Return To Menu"), wxDefaultPosition, wxDefaultSize, 0);
    button_config =new wxBoxSizer(wxHORIZONTAL);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom
    window_layout->Add(button_config,0,wxALIGN_CENTER,10);


    /*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

}

void GAME_Frame::OnAbout(wxCommandEvent &event){
    wxMessageBox("Welcome to Jack's Bank!\n"
                 "\nJack's Bank is an application designed to act as a game and bank"
                 "\n\nThere are 3 Windows: "
                 "\n\t1) Main Window to choose settings"
                 "\n\t2) Game Window to play black jack's game"
                 "\n\t3) Bank Window for depositing, withdrawls, and checking total balance",
                 "About Jacks Bank", wxOK | wxICON_INFORMATION);
}

void GAME_Frame::OnExit(wxCommandEvent &event){
    cout << "OnExit: Exiting Rock-Paper-Scissors app!" << endl;
    Close(true);
}



void GAME_Frame::OnClick_Hit(wxCommandEvent &event){
    cout << "Hit Card" << endl;
   
}

void GAME_Frame::OnClick_Stay(wxCommandEvent &event){
    cout << "Stay Card" << endl;
   
}


void GAME_Frame::OnClick_Return(wxCommandEvent &event){
    cout << "On retrun to menu button" << endl;
   
}

