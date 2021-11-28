#include <wx/wx.h>

#include <iostream>
#include "headers/gameFrame.h" //main class
#include "headers/betFrame.h"
#include "headers/mainFrame.h" // other class


using namespace std;

wxBEGIN_EVENT_TABLE(GAME_Frame, wxFrame)
    EVT_MENU(ID_RestartGame, GAME_Frame::OnRestart)
    EVT_MENU(wxID_ABOUT, GAME_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, GAME_Frame::OnExit)

    EVT_BUTTON(ID_stay_card, GAME_Frame::OnClick_Hit)
    EVT_BUTTON(ID_hit_card, GAME_Frame::OnClick_Stay)
    EVT_BUTTON(ID_returns, GAME_Frame::OnClick_Return)
wxEND_EVENT_TABLE()


GAME_Frame::GAME_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size){
/*Menu Top Bar*/
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_RestartGame, "R&estart...\tCtrl-H", "Restart Game");
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
    window_layout->AddSpacer(20);


/*Dealer*/
    wxFont dealer_title_font(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Dealer"), wxPoint(50, 15));
    heading->SetFont(dealer_title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);

/*CARDS*/
    wxColour card_color, red_labels, black_labels;
    card_color.Set(wxT("#6CE3E5"));
    red_labels.Set(wxT("#CF3C21"));
    black_labels.Set(wxT("#000000"));


    wxBoxSizer *dealer_cards = new wxBoxSizer(wxHORIZONTAL);


    card_1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_1->SetBackgroundColour(card_color);
    card_1_info_dealer = new wxStaticText(card_1, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_1_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_1, 1, wxEXPAND | wxALL, 20);
  

    card_2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_2->SetBackgroundColour(card_color);
    card_2_info_dealer = new wxStaticText(card_2, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_2_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_2, 1, wxEXPAND | wxALL, 20);


    card_3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_3->SetBackgroundColour(card_color);
    card_3_info_dealer = new wxStaticText(card_3, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_3_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_3, 1, wxEXPAND | wxALL, 20);


    card_4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_4->SetBackgroundColour(card_color);
    card_4_info_dealer = new wxStaticText(card_4, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_4_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_4, 1, wxEXPAND | wxALL, 20);


    card_5 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_5->SetBackgroundColour(card_color);
    card_5_info_dealer = new wxStaticText(card_5, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_5_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_5, 1, wxEXPAND | wxALL, 20);


    window_layout->Add(dealer_cards, 0, wxALIGN_CENTER, 5);
    window_layout->AddSpacer(10);



/*Score*/
    wxFont top_row_line(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("========================================="), wxPoint(50, 15));
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
    heading = new wxStaticText(this, wxID_ANY, wxT("========================================="), wxPoint(50, 15));
    heading->SetFont(bottom_row_line);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);


/*Player*/
    wxFont player_title_font(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Player"), wxPoint(50, 15));
    heading->SetFont(player_title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);
        
    /*cards*/
    wxBoxSizer *player_cards = new wxBoxSizer(wxHORIZONTAL);


    card_1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_1->SetBackgroundColour(card_color);
    card_1_info_player = new wxStaticText(card_1, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_1_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_1, 1, wxEXPAND | wxALL, 20);
  

    card_2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_2->SetBackgroundColour(card_color);
    card_2_info_player = new wxStaticText(card_2, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_2_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_2, 1, wxEXPAND | wxALL, 20);


    card_3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_3->SetBackgroundColour(card_color);
    card_3_info_player = new wxStaticText(card_3, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_3_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_3, 1, wxEXPAND | wxALL, 20);


    card_4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_4->SetBackgroundColour(card_color);
    card_4_info_player = new wxStaticText(card_4, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_4_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_4, 1, wxEXPAND | wxALL, 20);


    card_5 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_5->SetBackgroundColour(card_color);
    card_5_info_player = new wxStaticText(card_5, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_5_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_5, 1, wxEXPAND | wxALL, 20);


    window_layout->Add(player_cards, 0, wxALIGN_CENTER,5);
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
    window_layout->AddSpacer(40);



    /* Return Button */
    setup_button_config = new wxButton(this, ID_returns, _T("Play Again"), wxDefaultPosition, wxDefaultSize, 0);
    button_config =new wxBoxSizer(wxHORIZONTAL);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom
    window_layout->Add(button_config,0,wxALIGN_CENTER,10);


    /*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

    /*Variables*/
    played_round = false;
    dealer_cards_counter = 0;
    player_cards_counter = 0;
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

void GAME_Frame::OnRestart(wxCommandEvent &event){
    Menu_Window = new MAIN_Frame("", wxPoint(50, 50), wxSize(450, 640));
    Menu_Window->Center();
    Menu_Window->Show(true);
    Menu_Window->wallet_updated(money_betted);
    // Menu_Window->set_config(slider->GetValue());

    Close(true); // closes window
}


void GAME_Frame::OnClick_Hit(wxCommandEvent &event){
    // played_round = true;
    std::cout << "Bye";
   
}

void GAME_Frame::OnClick_Stay(wxCommandEvent &event){
    std::cout << "Hi";
}



void GAME_Frame::OnClick_Return(wxCommandEvent &event){
    cout << "On retrun to menu button" << endl;
    if(played_round){
        Bet_Window = new BET_Frame("", wxPoint(50, 50), wxSize(450, 640));
        Bet_Window->Center();
        Bet_Window->Show(true);
        Bet_Window->set_wallet_money(money_betted);

        Close(true);
    }
   
}



//////////////////////////////Functions//////////////////
void GAME_Frame::user_information(int bet_money, int wallet_money){
    money_betted = bet_money;
    money_wallet = wallet_money;
    Bet_Money->SetLabel(wxString::Format(wxT("$%i"), bet_money));
}


void GAME_Frame::set_dealer_card(){
    //RETRIEVE CARD HERE: is it spades? heart, 3?, red?
    int card_number = 0; // placeholder
    string card_letter;

    if(dealer_cards_counter == 0){
        card_1_info_dealer->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(dealer_cards_counter == 1){
        card_2_info_dealer->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(dealer_cards_counter == 2){
        card_3_info_dealer->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(dealer_cards_counter == 3){
        card_4_info_dealer->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(dealer_cards_counter == 4){
        card_5_info_dealer->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }
    dealer_cards_counter++;

    CPU_Score->SetLabel(wxString::Format(wxT("[%i]"), card_number));
}


void GAME_Frame::set_player_card(){
    //RETRIEVE CARD HERE: is it spades? heart, 3?, red?
    int card_number = 0; // placeholder
    string card_letter;

    if(player_cards_counter == 0){
        card_1_info_player->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(player_cards_counter == 1){
        card_2_info_player->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(player_cards_counter == 2){
        card_3_info_player->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(player_cards_counter == 3){
        card_4_info_player->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }else if(player_cards_counter == 4){
        card_5_info_player->SetLabel(wxString::Format(wxT("\n\n%i\n\n%s"), card_number, card_letter));
    }
    player_cards_counter++;


    Player_Score->SetLabel(wxString::Format(wxT("[%i]"), card_number));
}