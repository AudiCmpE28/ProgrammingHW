#include <iostream>
#include <wx/wx.h>
#include "headers/RPSframe.h"

using namespace std;

wxBEGIN_EVENT_TABLE(RPS_Frame, wxFrame)
    EVT_MENU(ID_Hello,    RPS_Frame::OnHello)
    EVT_MENU(ID_Bonjour,  RPS_Frame::OnBonjour)
    EVT_MENU(ID_GutenTag, RPS_Frame::OnGutenTag)
    EVT_MENU(wxID_ABOUT,  RPS_Frame::OnAbout)
    EVT_MENU(wxID_EXIT,   RPS_Frame::OnExit)
wxEND_EVENT_TABLE()

RPS_Frame::RPS_Frame(const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Status string: Hello!");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Bonjour, "&Bonjour...\tCtrl-B", "Status string: Bonjour!");
    menuFile->Append(ID_GutenTag, "&Guten Tag...\tCtrl-G", "Status string: Guten Tag!");
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Status string: Quit Wx-helloworld");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to Jurrasic Park!");
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
    cout << "OnExit: Exiting Hello World app!" << endl;
    Close(true);
}

void RPS_Frame::OnHello(wxCommandEvent& event) {
    wxMessageBox("Hello, world!",
                 "OnHello", wxOK | wxICON_INFORMATION);
}

void RPS_Frame::OnBonjour(wxCommandEvent& event) {
    wxMessageBox("Bonjour, monde!",
                 "OnBonjour", wxOK | wxICON_INFORMATION);
}

void RPS_Frame::OnGutenTag(wxCommandEvent& event) {
    wxMessageBox("Guten Tag, Welt!",
                 "OnGutenTag", wxOK | wxICON_INFORMATION);
}
