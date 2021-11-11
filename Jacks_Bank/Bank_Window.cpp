#include <wx/wx.h>
#include "wx/sizer.h"

#include "headers/bankFrame.h" //main class


wxBEGIN_EVENT_TABLE(BANK_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, BANK_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, BANK_Frame::OnExit)

    EVT_BUTTON(ID_bank_deposit, BANK_Frame::OnClick_Deposit)   
    EVT_BUTTON(ID_bank_withdraw, BANK_Frame::OnClick_Withdraw) 
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
    heading = new wxStaticText(this, wxID_ANY, wxT("Jack's Bank"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);

/* ATM */
    /* Total Balance */
    wxFont total_balance_heading(14, wxDEFAULT, wxNORMAL, wxBOLD);
    total_balance = new wxStaticText(this, wxID_ANY, wxT("0.0"), wxPoint(30, 15));
    total_balance->SetFont(total_balance_heading);
    window_layout->Add(total_balance, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);

    /* Enter Amount */
    // Create the textbox to input username 
    amount_entered = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxSize(200, 50));
    //add to window layout
    window_layout->Add(amount_entered, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(50);

    /* Deposit and Withdraw Button Layout */
    button_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    setup_button_config = new wxButton(this, ID_bank_deposit, _T("Deposit"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom

    button_config->AddSpacer(40); //space between them

    setup_button_config = new wxButton(this, ID_bank_withdraw, _T("Withdraw"), wxDefaultPosition, wxDefaultSize, 0);
    button_config->Add(setup_button_config, 0, wxALL, 5);

    window_layout->Add(button_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(10);


/*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

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
    std::cout << "Depoist ma Money" << std::endl;

}

void BANK_Frame::OnClick_Withdraw(wxCommandEvent &event){
    std::cout << "Withdraw ma Money" << std::endl;

}