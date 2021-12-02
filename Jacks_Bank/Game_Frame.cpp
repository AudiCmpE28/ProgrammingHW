#include <wx/wx.h>

#include <iostream>
#include "headers/gameFrame.h" //main class
#include "headers/betFrame.h"
#include "headers/mainFrame.h" // other class


using namespace std;


//A Table that connects ID with function. As seen in constructor, buttons and menu
//uses ID, which then calls function upon being pressed and will execute said
//function
wxBEGIN_EVENT_TABLE(GAME_Frame, wxFrame)
    EVT_MENU(ID_RestartGame, GAME_Frame::OnRestart)
    EVT_MENU(wxID_ABOUT, GAME_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, GAME_Frame::OnExit)

    EVT_BUTTON(ID_hit_card, GAME_Frame::OnClick_Hit)
    EVT_BUTTON(ID_stay_card, GAME_Frame::OnClick_Stay)
    EVT_BUTTON(ID_returns, GAME_Frame::OnClick_Return)
wxEND_EVENT_TABLE()


//Essentially Constructor that will set the GUI part of the program. Most setup cannot be
//modified during program execution
GAME_Frame::GAME_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size){

/*Menu Top Bar*/
    wxMenu *menuFile = new wxMenu; //wxMenu is a tab that will apear in places like 'file'
    //Add items to menu, should be able to add your own Ctrl-X that will activate but
    //not necessary
    menuFile->Append(ID_RestartGame, "R&estart...\tCtrl-H", "Restart Game");
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Quit the Game");

    wxMenu *menuHelp = new wxMenu;//creates a tab in wxMenu such as menuFile
    menuHelp->Append(wxID_ABOUT, "&About...\tCtrl-P", "Game Instructions!");

    wxMenuBar *menuBar = new wxMenuBar; //Specifcally creates the bar for the menu
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help"); //add boith menu tabs to bar
    SetMenuBar(menuBar); //execute

    CreateStatusBar();
    SetStatusText("For Game Info, go to 'Help->About' or 'Ctrl-P'");

    /* SET UP */
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    window_layout = new wxBoxSizer(wxVERTICAL); //items placed vertical


/*After menu, anything we add will show in the order we execute them
unless we specify the poing in the window. wxBoxSizer will allow us to place thins either 
vertically or horizontally (for example, buttons next to eachother left and right in horizontal,
or upp or bwloe when vertical).

window_layout will place things from top to bottom as we add them. Names can be
changed to anything as long as its a pointer variable such as
wxBoxSizer *newVariable = new wxBoxSize
*/

/*Money Bet*/
    display_bet = new wxBoxSizer(wxHORIZONTAL); //

    /*wxFonts for some reason are the only variable that must be declared as a new variable,
    cannot reuse (but u can try*/
    wxFont wallet_font(12, wxDEFAULT, wxNORMAL, wxBOLD); //select font size, wxBolf can be changed todefault
    
    //reason for declaring variables as private in the header is because we can change it
    //in a function. heading isnt but keep eye for unique named variables
    heading = new wxStaticText(this, wxID_ANY, wxT("Bet Money: "), wxPoint(50, 15)); 
    
    heading->SetFont(wallet_font); //set font to above text
    //add text to the box of gui
    display_bet->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    wxFont Bet_Money_heading(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    Bet_Money = new wxStaticText(this, wxID_ANY, wxT("$0.00"), wxPoint(30, 15));
    Bet_Money->SetFont(Bet_Money_heading);
    display_bet->Add(Bet_Money, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    window_layout->Add(display_bet, 0, wxALIGN_RIGHT, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(20);//adds space between top and bottom items


/*Dealer*/
    wxFont dealer_title_font(15, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Dealer"), wxPoint(50, 15));
    heading->SetFont(dealer_title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);

/*CARDS*/
    //declare colors instead of hex, like in snapshop color file
    wxColour card_color, red_labels, black_labels;
    card_color.Set(wxT("#6CE3E5"));
    red_labels.Set(wxT("#CF3C21"));
    black_labels.Set(wxT("#000000"));


    //will be used to place cards next to eachother
    wxBoxSizer *dealer_cards = new wxBoxSizer(wxHORIZONTAL);

    //card variables are declared in header which can be modified

    //set box size to act as a card
    card_1_d = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_1_d->SetBackgroundColour(black_labels); //set card color
    //set string to display in card
    card_1_info_dealer = new wxStaticText(card_1_d, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_1_info_dealer->SetForegroundColour(red_labels); //set font of card
    dealer_cards->Add(card_1_d, 1, wxEXPAND | wxALL, 20);//add card to horizontal lineup
  

    card_2_d = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_2_d->SetBackgroundColour(black_labels);
    card_2_info_dealer = new wxStaticText(card_2_d, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_2_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_2_d, 1, wxEXPAND | wxALL, 20);


    card_3_d = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_3_d->SetBackgroundColour(black_labels);
    card_3_info_dealer = new wxStaticText(card_3_d, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_3_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_3_d, 1, wxEXPAND | wxALL, 20);


    card_4_d = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_4_d->SetBackgroundColour(black_labels);
    card_4_info_dealer = new wxStaticText(card_4_d, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_4_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_4_d, 1, wxEXPAND | wxALL, 20);


    card_5_d = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_5_d->SetBackgroundColour(black_labels);
    card_5_info_dealer = new wxStaticText(card_5_d, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_5_info_dealer->SetForegroundColour(red_labels);
    dealer_cards->Add(card_5_d, 1, wxEXPAND | wxALL, 20);


    window_layout->Add(dealer_cards, 0, wxALIGN_CENTER, 5); //add all cards to GUI
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

    scores->AddSpacer(120); //used to add space on horizotnal plane, not vertifcal like
                            //when we add to gui

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
    wxBoxSizer *player_cards = new wxBoxSizer(wxHORIZONTAL); //new deck of cards


    card_1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_1->SetBackgroundColour(black_labels);
    card_1_info_player = new wxStaticText(card_1, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_1_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_1, 1, wxEXPAND | wxALL, 20);
  

    card_2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_2->SetBackgroundColour(black_labels);
    card_2_info_player = new wxStaticText(card_2, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_2_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_2, 1, wxEXPAND | wxALL, 20);


    card_3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_3->SetBackgroundColour(black_labels);
    card_3_info_player = new wxStaticText(card_3, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_3_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_3, 1, wxEXPAND | wxALL, 20);


    card_4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_4->SetBackgroundColour(black_labels);
    card_4_info_player = new wxStaticText(card_4, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_4_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_4, 1, wxEXPAND | wxALL, 20);


    card_5 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(60,120));
    card_5->SetBackgroundColour(black_labels);
    card_5_info_player = new wxStaticText(card_5, wxID_ANY, wxT("\n\nJack's\n\nBank"), wxDefaultPosition);
    card_5_info_player->SetForegroundColour(red_labels);
    player_cards->Add(card_5, 1, wxEXPAND | wxALL, 20);


    window_layout->Add(player_cards, 0, wxALIGN_CENTER,5);
    window_layout->AddSpacer(20);


/*Buttons*/
    /* Hit Button Layout */
    button_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    //setup buttons with ID number to link to function, and string to display in butt
    setup_button_config = new wxButton(this, ID_hit_card, _T("HIT"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom
    button_config->AddSpacer(40); //space between them

    /*Stay Button Layout*/
    setup_button_config = new wxButton(this, ID_stay_card, _T("STAY"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5);//add button to horizotnal plane
    window_layout->Add(button_config, 0, wxALIGN_CENTER, 10);//add to GUI
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
    dealer_cards_counter = 0;
    player_cards_counter = 0;
}

void GAME_Frame::OnAbout(wxCommandEvent &event){
    //for pop up text box
    wxMessageBox("Welcome to Jack's Bank!\n"
                 "\nJack's Bank is an application designed to act as a game and bank"
                 "\n\nThere are 3 Windows: "
                 "\n\t1) Main Window to choose settings"
                 "\n\t2) Game Window to play black jack's game"
                 "\n\t3) Bank Window for depositing, withdrawls, and checking total balance",
                 "About Jacks Bank", wxOK | wxICON_INFORMATION);
}

void GAME_Frame::OnExit(wxCommandEvent &event){
    cout << "OnExit: Exiting Jack's Bank app!" << endl;
    Close(true);
}

void GAME_Frame::OnRestart(wxCommandEvent &event){
    Menu_Window = new MAIN_Frame("", wxPoint(50, 50), wxSize(450, 640)); //set up for new window gui
    Menu_Window->Center(); //make sure window is centered in computer
    Menu_Window->Show(true);//show the gui
    //function must be in public of the other window class, for example, wallet_update()
    // is located in the MAIN_frame class and primariply exists to pass variables 
    //so we dont lose the data
    Menu_Window->wallet_updated(money_betted); 
    // Menu_Window->set_config(slider->GetValue()); 

    Close(true); // closes current window
}


void GAME_Frame::dealer_final_stage(){
    card_game->dealerTurn();
    set_dealer_card();
}

void GAME_Frame::OnClick_Hit(wxCommandEvent &event){ //activated up button with linked id is pressed
    if(!card_game->get_Game_Over_Flag()){
        card_game->playerHit(true);
        set_player_card();

        if(card_game->get_player_busted() || card_game->get_Game_Over_Flag()){
            dealer_final_stage();
        }
    }

   
}

void GAME_Frame::OnClick_Stay(wxCommandEvent &event){
    if(!card_game->get_Game_Over_Flag()){
        card_game->playerHit(false);
        dealer_final_stage();
    }
}



void GAME_Frame::OnClick_Return(wxCommandEvent &event){
    cout << "On retrun to menu button" << endl;
    Bet_Window = new BET_Frame("", wxPoint(50, 50), wxSize(450, 640));
    Bet_Window->Center();
    Bet_Window->Show(true);
    Bet_Window->set_wallet_money(money_betted);

    Close(true);
 
   
}



//////////////////////////////Functions//////////////////
void GAME_Frame::user_information(int bet_money, int wallet_money){
    money_betted = bet_money;
    money_wallet = wallet_money;
    Bet_Money->SetLabel(wxString::Format(wxT("$%i"), bet_money));

    card_game = new Game();
    card_game->setPlayerBet(bet_money);
    card_game->initHands();
    
    int i = 0;
    while (i<2){
        set_dealer_card();
        set_player_card();
        i++;
    }
}


void GAME_Frame::set_dealer_card(){
    //RETRIEVE CARD HERE: is it spades? heart, 3?, red?
    vector<Card> dealerHand = card_game->getHand(card_game->forDealer);

    string card_number = dealerHand[dealer_cards_counter].cardValue(dealerHand[dealer_cards_counter].getValue());
    string card_letter = dealerHand[dealer_cards_counter].cardSuit(dealerHand[dealer_cards_counter].getSuit());

    

    if(dealer_cards_counter == 0){
        card_1_info_dealer->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_1_d->SetBackgroundColour("#6CE3E5");
    }else if(dealer_cards_counter == 1){
        card_2_info_dealer->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_2_d->SetBackgroundColour("#6CE3E5");
    }else if(dealer_cards_counter > 1){
    
        while(dealer_cards_counter < dealerHand.size()){
            card_number = dealerHand[dealer_cards_counter].cardValue(dealerHand[dealer_cards_counter].getValue());
            card_letter = dealerHand[dealer_cards_counter].cardSuit(dealerHand[dealer_cards_counter].getSuit());
            
            if(dealer_cards_counter == 2){
                card_3_info_dealer->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
                card_3_d->SetBackgroundColour("#6CE3E5");
            }else if(dealer_cards_counter == 3){
                card_4_info_dealer->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
                card_4_d->SetBackgroundColour("#6CE3E5");
            }else if(dealer_cards_counter == 4){
                card_5_info_dealer->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
                card_5_d->SetBackgroundColour("#6CE3E5");
            }
        dealer_cards_counter++;
        }
    }
    dealer_cards_counter++;

    int cpu_stance = card_game->getDealerScore();
    if (cpu_stance > 21){
        CPU_Score->SetLabel(wxString::Format(wxT("[BUST]")));
    }else{
        CPU_Score->SetLabel(wxString::Format(wxT("[%i]"), cpu_stance));
    }


    if(dealer_cards_counter > 2){
        int winner = card_game->returnWinner();
        string winner_string;
        if(winner == 1){
            winner_string = "Winner: YOU - the Player";
        }else if(winner == 2){
            winner_string = "Winner: CPU";
        }else{
            winner_string = "No Winner- Tied";
        }
        wxMessageBox(winner_string,
                "About Winner", wxOK | wxICON_INFORMATION);

    }

}


void GAME_Frame::set_player_card(){
    //RETRIEVE CARD HERE: is it spades? heart, 3?, red?
    vector<Card> playerHand = card_game->getHand(card_game->forPlayer);
    
    string card_number = playerHand[player_cards_counter].cardValue(playerHand[player_cards_counter].getValue());
    string card_letter = playerHand[player_cards_counter].cardSuit(playerHand[player_cards_counter].getSuit());;
    

    if(player_cards_counter == 0){
        card_1_info_player->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_1->SetBackgroundColour("#6CE3E5");
    }else if(player_cards_counter == 1){
        card_2_info_player->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_2->SetBackgroundColour("#6CE3E5");
    }else if(player_cards_counter == 2){
        card_3_info_player->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_3->SetBackgroundColour("#6CE3E5");
    }else if(player_cards_counter == 3){
        card_4_info_player->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_4->SetBackgroundColour("#6CE3E5");
    }else if(player_cards_counter == 4){
        card_5_info_player->SetLabel(wxString::Format(wxT("\n\n%s\n\n%s"), card_number, card_letter));
        card_5->SetBackgroundColour("#6CE3E5");
    }
    player_cards_counter++;
    

    int player_Stance = card_game->getPlayerScore();
    if (player_Stance > 21){
        Player_Score->SetLabel(wxString::Format(wxT("[BUST]")));
    }else{
        Player_Score->SetLabel(wxString::Format(wxT("[%i]"), player_Stance));
    }

    // cout << "{PLAYA} " << endl;
    // for(int i = 0; i < playerHand.size();i++){
    //     // dealerHand[i].cardValue(dealerHand[i].getValue());
    //     // dealerHand[i].cardSuit(dealerHand[i].getSuit());
        
    //     playerHand[i].printCardDetails();
    // }
    
}