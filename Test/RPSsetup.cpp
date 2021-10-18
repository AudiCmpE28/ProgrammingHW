#include <iostream>
#include <wx/wx.h>
#include "headers/RPSsetup.h"

#include "wx/sizer.h"
#include "icons/slider.xpm"
using namespace std;

wxBEGIN_EVENT_TABLE(RPS_Setup, wxFrame)
    EVT_MENU(ID_Hello2,    RPS_Setup::OnHello)
    EVT_MENU(wxID_ABOUT,  RPS_Setup::OnAbout)
    EVT_MENU(wxID_EXIT,   RPS_Setup::OnExit)

    EVT_BUTTON(buttonRandCPU_ID, RPS_Setup::OnClick_RandCPU)
    EVT_BUTTON(buttonSmartCPU_ID, RPS_Setup::OnClick_SmartCPU)
    EVT_BUTTON(buttonGeniusCPU_ID, RPS_Setup::OnClick_GeniusCPU)
    // EVT_SLIDER(ID_SLIDER, RPS_Setup::OnScroll)

    EVT_BUTTON(buttonSubmit_ID, RPS_Setup::OnClick_SubmitInfo)

wxEND_EVENT_TABLE()



RPS_Setup::RPS_Setup(const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame(NULL, wxID_ANY, title, pos, size) {

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello2, "&Hello...\tCtrl-H", "Status string: Welcome!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X", "Status string: Quit the Game");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to RPS!      For Game Info, go to Help -> About");

/* SET UP */
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    window_layout = new wxBoxSizer(wxVERTICAL); //items placed vertical

    //Title
    window_layout->AddSpacer(20);
    wxFont title_font(16, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Rock Paper Scissors Configuration"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);


/*CPU Mode */
    // Title
    wxFont cpuMode_font(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    heading = new wxStaticText(this, wxID_ANY, wxT("Choose CPU Mode:"), wxPoint(50, 15));
    heading->SetFont(cpuMode_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);

    // Button Set
    setup_box_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    setup_button_config = new wxButton(this, buttonRandCPU_ID, _T("Rand CPU"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom

    setup_button_config = new wxButton(this, buttonSmartCPU_ID, _T("Smart CPU"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(setup_button_config, 0, wxALL, 5);

    setup_button_config = new wxButton(this, buttonGeniusCPU_ID, _T("Genius CPU"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(setup_button_config, 0, wxALL, 5);

    window_layout->Add(setup_box_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(50);


/*Round Amount */
    // Slider Title
    wxFont slider_title(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    heading = new wxStaticText(this, wxID_ANY, wxT("Choose Amount of Rounds:"), wxPoint(50, 15));
    heading->SetFont(slider_title);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(10);
    
    // Slider for Rounds
    fill = 0;
    slider = new wxSlider(this, ID_SLIDER, 0, 0, 20, wxPoint(30, 50), wxSize(140, -1), wxSL_HORIZONTAL);
    Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(RPS_Setup::OnScroll)); 
    window_layout->Add(slider, 0, wxALIGN_CENTER, 10);
    
    //Slider Rounds Number selected
    wxFont display_slider(8, wxDEFAULT, wxNORMAL, wxDEFAULT);
    roundNum = new wxStaticText(this, wxID_ANY, wxT("Rounds: 0"), wxPoint(50, 15)); // initial message
    roundNum->SetFont(display_slider);
    window_layout->Add(roundNum, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(80);

/*Submit Button*/
    //button config
    submit_button_config = new wxButton(this, buttonSubmit_ID, _T("Submit Configuration"), wxDefaultPosition, wxDefaultSize, 0);
    window_layout->Add(submit_button_config, 0, wxALIGN_BOTTOM | wxALIGN_CENTER , 10);
    // window_layout->AddSpacer(20);


/*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();   
}

void RPS_Setup::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Welcome to Rock, Paper, Scissors!\n" 
                 "\nThe game is simple, pick rock, paper, or scissors by entering a number between 1 to 3."
                 "\n\nThere are only 3 rules to win or lose: "
                 "\n\t1) Paper beats Rock" 
                 "\n\t2) Scissors beats paper" 
                 "\n\t3) Rock bears Scissors", 
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void RPS_Setup::OnExit(wxCommandEvent& event) {
    cout << "OnExit: Exiting Rock-Paper-Scissors app!" << endl;
    Close(true);
}

void RPS_Setup::OnHello(wxCommandEvent& event) {
    wxMessageBox("Hello, foo!",
                 "OnHello", wxOK | wxICON_INFORMATION);
}


/*SET UP*/

void RPS_Setup::OnClick_RandCPU(wxCommandEvent& event) {
    wxMessageBox("RandCPU!", "RandCPU Button", wxOK | wxICON_INFORMATION, this);
}

void RPS_Setup::OnClick_SmartCPU(wxCommandEvent& event) {
    wxMessageBox("SmartCPU!", "SmartCPU Button", wxOK | wxICON_INFORMATION, this);
}

void RPS_Setup::OnClick_GeniusCPU(wxCommandEvent& event) {
    wxMessageBox("GeniusCPU!", "GeniusCPU Button", wxOK | wxICON_INFORMATION, this);
}

Slider::Slider(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200)) {
    Center();
}

void RPS_Setup::OnScroll(wxScrollEvent& event) {
  fill = slider->GetValue();
  roundNum->SetLabel(wxString::Format(wxT("Rounds: %i"), fill)); //update display
  wxDisplayChangedEvent(); // update immediatelly do not wait a second
  Refresh();
}

void RPS_Setup::OnClick_SubmitInfo(wxCommandEvent& event) {
    wxMessageBox("Submitted!", "SubmitInfo Button", wxOK | wxICON_INFORMATION, this);
}