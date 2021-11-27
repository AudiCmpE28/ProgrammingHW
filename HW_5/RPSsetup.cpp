#include <wx/wx.h>
#include "headers/RPSsetup.h"
#include "headers/RPSframe.h" // other class

#include "headers/Game.h"

using namespace std;

wxBEGIN_EVENT_TABLE(MAIN_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, MAIN_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, MAIN_Frame::OnExit)

    EVT_BUTTON(buttonRandCPU_ID, MAIN_Frame::OnClick_RandCPU)
    EVT_BUTTON(buttonSmartCPU_ID, MAIN_Frame::OnClick_SmartCPU)
    EVT_BUTTON(buttonGeniusCPU_ID, MAIN_Frame::OnClick_GeniusCPU)
    // EVT_SLIDER(ID_SLIDER, MAIN_Frame::OnScroll)

    EVT_BUTTON(buttonSubmit_ID, MAIN_Frame::OnClick_SubmitInfo)
wxEND_EVENT_TABLE()

MAIN_Frame::MAIN_Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
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
    window_layout->AddSpacer(10);

    // Button Set Display
    wxFont cpuMode_display(8, wxDEFAULT, wxNORMAL, wxDEFAULT);
    CPUmode_display = new wxStaticText(this, wxID_ANY, wxT("CPU Mode Selected: None"), wxPoint(50, 15));
    CPUmode_display->SetFont(cpuMode_display);
    window_layout->Add(CPUmode_display, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
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
    slider = new wxSlider(this, ID_SLIDER, 1, 1, 20, wxPoint(30, 50), wxSize(140, -1), wxSL_HORIZONTAL);
    Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(MAIN_Frame::OnScroll));
    window_layout->Add(slider, 0, wxALIGN_CENTER, 10);

    //Slider Rounds Number selected
    wxFont display_slider(8, wxDEFAULT, wxNORMAL, wxDEFAULT);
    roundNum = new wxStaticText(this, wxID_ANY, wxT("Rounds: Default 1"), wxPoint(50, 15)); // initial message
    roundNum->SetFont(display_slider);
    window_layout->Add(roundNum, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(70);

    /*Submit Button*/
    //button config
    submit_button_config = new wxButton(this, buttonSubmit_ID, _T("Submit Configuration"), wxDefaultPosition, wxDefaultSize, 0);
    window_layout->Add(submit_button_config, 0, wxALIGN_BOTTOM | wxALIGN_CENTER, 10);
    window_layout->AddSpacer(10);

    /*Finalize layout*/
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

    /*Declare variables*/
    CPUMode = -1;
}

void MAIN_Frame::OnAbout(wxCommandEvent &event){
    wxMessageBox("Welcome to Rock, Paper, Scissors!\n"
                 "\nThe game is simple, pick rock, paper, or scissors by entering a number between 1 to 3."
                 "\n\nThere are only 3 rules to win or lose: "
                 "\n\t1) Paper beats Rock"
                 "\n\t2) Scissors beats paper"
                 "\n\t3) Rock beats Scissors",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MAIN_Frame::OnExit(wxCommandEvent &event){
    cout << "OnExit: Exiting Rock-Paper-Scissors app!" << endl;
    Close(true);
}

/*SET UP*/

void MAIN_Frame::OnClick_RandCPU(wxCommandEvent &event){
    CPUmode_display->SetLabel("CPU Mode Selected: Random");
    CPUMode = 1;
}

void MAIN_Frame::OnClick_SmartCPU(wxCommandEvent &event){
    CPUmode_display->SetLabel("CPU Mode Selected: Smart");
    CPUMode = 2;
}

void MAIN_Frame::OnClick_GeniusCPU(wxCommandEvent &event){
    // CPUmode_display->SetLabel("CPU Mode Selected: Genius");
    // CPUMode = 3;
    CPUmode_display->SetLabel("Genius CPU DLC Locked ~ Coming Soon");
    CPUMode = -1; //temporary
}

Slider::Slider(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200))
{
    Center();
}

void MAIN_Frame::OnScroll(wxScrollEvent &event) {
    fill = slider->GetValue();
    roundNum->SetLabel(wxString::Format(wxT("Rounds: %i"), fill)); //update display
    wxDisplayChangedEvent();                                       // update immediatelly do not wait a second
    Refresh();
}

void MAIN_Frame::OnClick_SubmitInfo(wxCommandEvent &event){
    if (CPUMode == -1) {
        wxMessageBox("Please Select CPU Mode!\n",
                     "No CPU Mode Selected", wxOK | wxICON_INFORMATION);
    } else {
        RPS_Game_Frame = new GAME_Frame("", wxPoint(50, 50), wxSize(450, 640));
        RPS_Game_Frame->Center();
        RPS_Game_Frame->Show(true);
        RPS_Game_Frame->set_config(slider->GetValue(), CPUMode);

        Close(true); // closes window
        // Destroy(); //force closes window [Dangerous]
    }
}
