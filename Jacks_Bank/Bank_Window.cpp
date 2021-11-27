#include <wx/wx.h>
#include "wx/sizer.h"

#include "headers/bankFrame.h" //main class
#include "headers/mainFrame.h"

wxBEGIN_EVENT_TABLE(BANK_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, BANK_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, BANK_Frame::OnExit)

    EVT_BUTTON(ID_bank_deposit, BANK_Frame::OnClick_Deposit)   
    EVT_BUTTON(ID_bank_withdraw, BANK_Frame::OnClick_Withdraw) 
    EVT_BUTTON(ID_return, BANK_Frame::OnClick_Return)
wxEND_EVENT_TABLE()

BANK_Frame::BANK_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
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
    heading = new wxStaticText(this, wxID_ANY, wxT(">> Jack's Bank <<"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);

/* ATM */

    /* Total Balance */
    // wxStaticBox *box = new wxStaticBox(this, wxID_ANY, "StaticBox");
    

    wxFont bank_total(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("BANK Total"), wxPoint(50, 15));
    heading->SetFont(bank_total);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(5);

    wxFont total_balance_heading(14, wxDEFAULT, wxNORMAL, wxDEFAULT);
    total_balance = new wxStaticText(this, wxID_ANY, wxT("$0.00"), wxPoint(30, 15));
    total_balance->SetFont(total_balance_heading);
    window_layout->Add(total_balance, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);



    /* Enter Amount */
    // Create the textbox to input username 
    ATM_Display = new wxBoxSizer(wxHORIZONTAL); 

    wxFont ATM_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Enter $"), wxPoint(50, 15));
    heading->SetFont(ATM_font);
    ATM_Display->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    amount_entered = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxSize(200, 50));
    ATM_Display->Add(amount_entered, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    
    window_layout->Add(ATM_Display, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(30);


    /* Deposit Button Layout */
    button_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    setup_button_config = new wxButton(this, ID_bank_deposit, _T("Deposit"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom

    button_config->AddSpacer(40); //space between them

    /*Withdraw Button Layout*/
    setup_button_config = new wxButton(this, ID_bank_withdraw, _T("Withdraw"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5);

    window_layout->Add(button_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(40);




/* Wallet Balance */
    Wallet_Display = new wxBoxSizer(wxHORIZONTAL); 

    wxFont wallet_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Wallet Amount: "), wxPoint(50, 15));
    heading->SetFont(wallet_font);
    Wallet_Display->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    wxFont wallet_heading(14, wxDEFAULT, wxNORMAL, wxDEFAULT);
    wallet = new wxStaticText(this, wxID_ANY, wxT("$0.00"), wxPoint(30, 15));
    wallet->SetFont(wallet_heading);
    Wallet_Display->Add(wallet, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion


    window_layout->Add(Wallet_Display, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(60);


/*vertical spacer for return button*/
    /* Return Button */
    setup_button_config = new wxButton(this, ID_return, _T("Return To Menu"), wxDefaultPosition, wxDefaultSize, 0);
    button_config =new wxBoxSizer(wxHORIZONTAL);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom
    window_layout->Add(button_config,0,wxALIGN_CENTER,10);



/*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

/*Variables*/
    bank_money = 0;
}

void BANK_Frame::OnAbout(wxCommandEvent &event){
    wxMessageBox("Welcome to Jack's Bank!\n"
                 "\nJack's Bank is an application designed to act as a game and bank"
                 "\n\nThere are 3 Windows: "
                 "\n\t1) Main Window to choose settings"
                 "\n\t2) Game Window to play black jack's game"
                 "\n\t3) Bank Window for depositing, withdrawls, and checking total balance",
                 "About Jacks Bank", wxOK | wxICON_INFORMATION);
}

void BANK_Frame::OnExit(wxCommandEvent &event){
    std::cout << "OnExit: Exiting Rock-Paper-Scissors app!" << std::endl;
    Close(true);
}



/* Buttons Functions */
void BANK_Frame::OnClick_Deposit(wxCommandEvent &event){
    int total = atoi(amount_entered->GetValue());
    if ((wallet_money-total) >= 0){
        bank_money = bank_money + total;
        total_balance->SetLabel(wxString::Format(wxT("$%i"), bank_money));
        wallet_money_updated(wallet_money-total);
    }
}



void BANK_Frame::OnClick_Withdraw(wxCommandEvent &event){
    int total = atoi(amount_entered->GetValue());
    if((bank_money-total) >= 0){
        bank_money = bank_money - total;
        total_balance->SetLabel(wxString::Format(wxT("$%i"), bank_money));
        wallet_money_updated(wallet_money+total);
    }
}

void BANK_Frame::OnClick_Return(wxCommandEvent &event){
    Menu_Window = new MAIN_Frame("", wxPoint(50, 50), wxSize(450, 640));
    Menu_Window->Center();
    Menu_Window->Show(true);
    Menu_Window->wallet_updated(wallet_money);

    Close(true); // closes window

}


void BANK_Frame::wallet_money_updated(int money){
    wallet_money = money;
    wallet->SetLabel(wxString::Format(wxT("$%i"), money));
}