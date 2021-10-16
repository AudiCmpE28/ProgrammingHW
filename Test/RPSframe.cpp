#include <iostream>
#include <wx/wx.h>
#include "headers/RPSframe.h"

#include "wx/sizer.h"

#include "icons/slider.xpm"
using namespace std;

const long RPS_Frame::idButtonRock = ::wxNewId();       //Rock Button
const long RPS_Frame::idButtonPaper = ::wxNewId();      //Paper Button
const long RPS_Frame::idButtonScissors = ::wxNewId();   //Scissors Button

wxBEGIN_EVENT_TABLE(RPS_Frame, wxFrame)
    EVT_MENU(ID_Hello,    RPS_Frame::OnHello)
    EVT_MENU(wxID_ABOUT,  RPS_Frame::OnAbout)
    EVT_MENU(wxID_EXIT,   RPS_Frame::OnExit)

    EVT_BUTTON(idButtonRock, RPS_Frame::OnClickRock)
    EVT_BUTTON(idButtonPaper, RPS_Frame::OnClickPaper)
    EVT_BUTTON(idButtonScissors, RPS_Frame::OnClickScissors)

    // EVT_SLIDER(ID_SLIDER, RPS_Frame::OnScroll)

wxEND_EVENT_TABLE()

RPS_Frame::RPS_Frame(const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Status string: Welcome!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Status string: Quit the Game");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Jurrasic Park!");

    // Button Set up
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    mainBox_config = new wxBoxSizer(wxHORIZONTAL);

    button_config = new wxButton(this, idButtonRock, _T("Rock"), wxDefaultPosition, wxDefaultSize, 0);
    mainBox_config->Add(button_config, 0, wxALL, 5);

    button_config = new wxButton(this, idButtonPaper, _T("Paper"), wxDefaultPosition, wxDefaultSize, 0);
    mainBox_config->Add(button_config, 0, wxALL, 5);

    button_config = new wxButton(this, idButtonScissors, _T("Scissors"), wxDefaultPosition, wxDefaultSize, 0);
    mainBox_config->Add(button_config, 0, wxALL, 5);

    this->SetSizer(mainBox_config);
    this->Layout();

    // Slider for Rounds
    fill = 0;
    slider = new wxSlider(this, ID_SLIDER, 0, 0, 20, wxPoint(30, 50), wxSize(140, -1), wxSL_HORIZONTAL);
    Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(RPS_Frame::OnScroll)); 
    
}

void RPS_Frame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Welcome to Rock, Paper, Scissors!\n" 
                 "\nThe game is simple, pick rock, paper, or scissors by entering a number between 1 to 3."
                 "\n\nThere are only 3 rules to win or lose: "
                 "\n\t1) Paper beats Rock" 
                 "\n\t2) Scissors beats paper" 
                 "\n\t3) Rock bears Scissors", 
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void RPS_Frame::OnExit(wxCommandEvent& event) {
    cout << "OnExit: Exiting Rock-Paper-Scissors app!" << endl;
    Close(true);
}

void RPS_Frame::OnHello(wxCommandEvent& event) {
    wxMessageBox("Hello, foo!",
                 "OnHello", wxOK | wxICON_INFORMATION);
}

void RPS_Frame::OnClickRock(wxCommandEvent& event) {
    // wxString msg = _T("Hello World");
    // wxString info = _T("linux-buddy");
    wxMessageBox("Rock!", "Rock Button", wxOK | wxICON_INFORMATION, this);
}

void RPS_Frame::OnClickPaper(wxCommandEvent& event) {
    wxMessageBox("Paper!", "Paper Button", wxOK | wxICON_INFORMATION, this);
}

void RPS_Frame::OnClickScissors(wxCommandEvent& event) {
    wxMessageBox("Scissors!", "Scissors Button", wxOK | wxICON_INFORMATION, this);
}


Slider::Slider(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200)) {
    Center();
}


void RPS_Frame::OnScroll(wxScrollEvent& event) {
  fill = slider->GetValue();
  cout << "OnScroll: " << fill << endl;
  wxDisplayChangedEvent();
  Refresh();
}