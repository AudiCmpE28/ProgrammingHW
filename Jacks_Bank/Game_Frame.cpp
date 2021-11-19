#include <wx/wx.h>

#include <iostream>
#include "headers/gameFrame.h" //main class

using namespace std;

wxBEGIN_EVENT_TABLE(GAME_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, GAME_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, GAME_Frame::OnExit)
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
    window_layout->AddSpacer(20);
    wxFont title_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Jack Black"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);


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