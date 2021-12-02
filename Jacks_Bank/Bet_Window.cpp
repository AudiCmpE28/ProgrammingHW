#include "headers/gameFrame.h"
#include "headers/mainFrame.h" // other class

#include "headers/betFrame.h"

using namespace std;

wxBEGIN_EVENT_TABLE(BET_Frame, wxFrame)
    // EVT_MENU(wxID_EXIT, BET_Frame::OnRestart)
    EVT_MENU(wxID_ABOUT, BET_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, BET_Frame::OnExit)
    

    EVT_BUTTON(ID_backMenu, BET_Frame::OnClick_Back_Menu)
    EVT_BUTTON(buttonSubmitBet_ID, BET_Frame::OnClick_SubmitInfo)
wxEND_EVENT_TABLE()

BET_Frame::BET_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
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
    wxFont title_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Bet Your Money"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);


/*Money Bet*/
    display_wallet = new wxBoxSizer(wxHORIZONTAL); 

    wxFont wallet_font(13, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Wallet: "), wxPoint(50, 15));
    heading->SetFont(wallet_font);
    display_wallet->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    string LcurrentWallet = "$" + to_string(mainPlayer.getWallet());
    wxFont Bet_Money_heading(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    Wallet_Money = new wxStaticText(this, wxID_ANY, wxT(currentWallet), wxPoint(30, 15));
    Wallet_Money->SetFont(Bet_Money_heading);
    display_wallet->Add(Wallet_Money, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    window_layout->Add(display_wallet, 0, wxALIGN_RIGHT, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);
   

    /*Round Amount */
    // Slider Title
    wxFont slider_title(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    heading = new wxStaticText(this, wxID_ANY, wxT("Choose Amount of Money to Bet:"), wxPoint(50, 15));
    heading->SetFont(slider_title);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);

    // Slider for Rounds
    fill = 1;
    //creeates slider linked to id wqhich s linked through connect function, not table
    //which is just a different way. 1 idk, but 1.0 to 20.0 is range which could be 1 to 20 but 
    //i tried using float for decimal aka cents in money. size numbers can be switched for
    //vertical
    slider = new wxSlider(this, ID_SLIDER, 1, 1.0, 20.0, wxPoint(30, 50), wxSize(140, -1), wxSL_HORIZONTAL);
    Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(BET_Frame::OnScroll));
    window_layout->Add(slider, 0, wxALIGN_CENTER, 10);

    //Slider Rounds Number selected
    wxFont display_slider(8, wxDEFAULT, wxNORMAL, wxDEFAULT);
    roundNum = new wxStaticText(this, wxID_ANY, wxT("Money Selected: $1"), wxPoint(50, 15)); // initial message
    roundNum->SetFont(display_slider);
    window_layout->Add(roundNum, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(70);



    /*Submit Button*/
    setup_box_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal

    button_config = new wxButton(this, buttonSubmitBet_ID, _T("Submit Bet"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(button_config, 0, wxALIGN_BOTTOM | wxALIGN_CENTER, 10);
    
    setup_box_config->AddSpacer(40);
    button_config = new wxButton(this, ID_backMenu, _T("Back to Menu"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(button_config, 0, wxALIGN_BOTTOM | wxALIGN_CENTER, 10);
  

    window_layout->Add(setup_box_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(10);

    /*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

    /*Declare variables*/
    CPUMode = -1;
}

void BET_Frame::OnAbout(wxCommandEvent &event){
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

void BET_Frame::OnExit(wxCommandEvent &event){
    cout << "OnExit: Exiting Jack's Bank app!" << endl;
    Close(true);
}



Slider::Slider(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200))
{
    Center();//places slider in the center of the GUI but inside, its linked
}

void BET_Frame::OnScroll(wxScrollEvent &event) {
    fill = slider->GetValue();//grtab value selected from user
    roundNum->SetLabel(wxString::Format(wxT("Money Selected: $%d"), fill)); //update display
    wxDisplayChangedEvent();                                       // update immediatelly do not wait a second
    Refresh();//refresh value asap

    
}

void BET_Frame::OnClick_SubmitInfo(wxCommandEvent &event){
    if((mainPlayer.getWallet() - fill)>=0){
    
        Game_Window = new GAME_Frame("", wxPoint(50, 50), wxSize(550, 840));
        Game_Window->Center();
        Game_Window->Show(true);
        Game_Window->initialize_game(slider->GetValue());

        Close(true); // closes window
    }
    else {
        Menu_Window = new MAIN_Frame("", wxPoint(50, 50), wxSize(450, 640));
        Menu_Window->Center();
        Menu_Window->Show(true);
        Menu_Window->wallet_updated();

        Close(true); // closes window
    }
}

void BET_Frame::OnClick_Back_Menu(wxCommandEvent &event){

        Menu_Window = new MAIN_Frame("", wxPoint(50, 50), wxSize(450, 640));
        Menu_Window->Center();
        Menu_Window->Show(true);
        Menu_Window->wallet_updated();

        Close(true); // closes window
        // Destroy(); //force closes window [Dangerous]
}


