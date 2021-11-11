#include "wx/sizer.h"

#include "headers/mainFrame.h" //main class
#include "headers/gameFrame.h" //other class
#include "headers/bankFrame.h" //other class

using namespace std;

/* ID's for Menu and Buttons */
wxBEGIN_EVENT_TABLE(MAIN_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT, MAIN_Frame::OnAbout)
    EVT_MENU(wxID_EXIT, MAIN_Frame::OnExit)

    EVT_BUTTON(ID_easy_button, MAIN_Frame::OnClick_Easy)   
    EVT_BUTTON(ID_medium_button, MAIN_Frame::OnClick_Medium)   
    EVT_BUTTON(ID_expert_button, MAIN_Frame::OnClick_Expert)   

    EVT_BUTTON(ID_game_button, MAIN_Frame::OnClick_Game_Window)   
    EVT_BUTTON(ID_bank_button, MAIN_Frame::OnClick_Bank_Window) 
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
    wxFont title_font(17, wxDEFAULT, wxNORMAL, wxBOLD);
    heading = new wxStaticText(this, wxID_ANY, wxT("Jack's Bank Set Up"), wxPoint(50, 15));
    heading->SetFont(title_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(50);

/* Mode */
    // Title
    wxFont game_mode_font(12, wxDEFAULT, wxNORMAL, wxDEFAULT);
    string game_mode = "Choose the following game mode:"
                        "\n\tEasy: You are given great amount of cash"
                        "\n\tMedium: You are given decent amount of cash"
                        "\n\tHard: You are given least amount of cash";
    
    heading = new wxStaticText(this, wxID_ANY, game_mode, wxPoint(50, 15));
    heading->SetFont(game_mode_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(15);

    // Button Layout
    setup_box_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    setup_button_config = new wxButton(this, ID_easy_button, _T("Easy"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(setup_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom

    setup_box_config->AddSpacer(20);
    setup_button_config = new wxButton(this, ID_medium_button, _T("Medium"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(setup_button_config, 0, wxALL, 5);
    setup_box_config->AddSpacer(20);

    setup_button_config = new wxButton(this, ID_expert_button, _T("Expert"), wxDefaultPosition, wxDefaultSize, 0);
    setup_box_config->Add(setup_button_config, 0, wxALL, 5);

    window_layout->Add(setup_box_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(10);

    // Button Set Display
    wxFont mode_selected_display(10, wxDEFAULT, wxNORMAL, wxDEFAULT);
    mode_display = new wxStaticText(this, wxID_ANY, wxT("Mode Selected: None"), wxPoint(50, 15));
    mode_display->SetFont(mode_selected_display);
    window_layout->Add(mode_display, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(40);


/* Username */
    // Title
    wxFont username_title(14, wxDEFAULT, wxNORMAL, wxDEFAULT);
    heading = new wxStaticText(this, wxID_ANY, wxT("Enter Username:"), wxPoint(50, 15));
    heading->SetFont(game_mode_font);
    window_layout->Add(heading, 0, wxALIGN_CENTER, 10); //addFunct, porportion, flag, postion
    window_layout->AddSpacer(15);

    // Create the textbox to input username 
    player_username = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                wxDefaultPosition, wxSize(200, 50));
    //add to window layout
    window_layout->Add(player_username, 0, wxALIGN_CENTER, 10);


/* Route to Next Window */
    // window_layout->AddSpacer(290);
    window_layout->AddSpacer(110);
    //button Layout
    window_box_config = new wxBoxSizer(wxHORIZONTAL); //buttons placed horizontal
    window_button_config = new wxButton(this, ID_game_button, _T("Game Window"), wxDefaultPosition, wxDefaultSize, 0);
    window_box_config->Add(window_button_config, 0, wxALL, 5); //wxAll = left | right | top | bottom

    window_box_config->AddSpacer(120);
    window_button_config = new wxButton(this, ID_bank_button, _T("Bank Window"), wxDefaultPosition, wxDefaultSize, 0);
    window_box_config->Add(window_button_config, 0, wxALL, 5);

    window_layout->Add(window_box_config, 0, wxALIGN_CENTER, 10);
    window_layout->AddSpacer(10);

/* Finalize layout */
    this->SetSizer(window_layout);
    this->Layout();
    this->Centre();

/* Variables Initialized */
    mode_selected = -1;
}

void MAIN_Frame::OnAbout(wxCommandEvent &event){
    wxMessageBox("Welcome to Jack's Bank!\n"
                 "\nJack's Bank is an application designed to act as a game and bank"
                 "\n\nThere are 3 Windows: "
                 "\n\t1) Main Window to choose settings"
                 "\n\t2) Game Window to play black jack's game"
                 "\n\t3) Bank Window for depositing, withdrawls, and checking total balance",
                 "About Jacks Bank", wxOK | wxICON_INFORMATION);
}

void MAIN_Frame::OnExit(wxCommandEvent &event){
    cout << "OnExit: Exiting Rock-Paper-Scissors app!" << endl;
    Close(true);
}

/* Button Set Up Functions */
void MAIN_Frame::OnClick_Easy(wxCommandEvent& event){
    cout << "Easy Button Pressed" << endl;
    mode_display->SetLabel("Mode Selected: Easy");
    mode_selected = 1;
}

void MAIN_Frame::OnClick_Medium(wxCommandEvent& event){
    cout << "Medium Button Pressed" << endl;
    mode_display->SetLabel("Mode Selected: Medium");
    mode_selected = 2;
}

void MAIN_Frame::OnClick_Expert(wxCommandEvent& event){
    cout << "Expert Button Pressed" << endl;
    mode_display->SetLabel("Mode Selected: Expert");
    mode_selected = 3;
}


/* Next Window Buttons */
void MAIN_Frame::OnClick_Game_Window(wxCommandEvent& event){
    cout << "Game Window Button Pressed" << endl;
    username_fetch = player_username->GetValue().ToStdString();

    if(mode_selected == -1 || username_fetch == "" || username_fetch == " "){
        wxMessageBox("Please Select Game Mode and Username!\n",
                     "Setup Incomplete", wxOK | wxICON_INFORMATION);
    }else{
        Game_Window = new GAME_Frame("", wxPoint(50, 50), wxSize(450, 640));
        Game_Window->Center();
        Game_Window->Show(true);
        // Game_Window->send_data(mode_selected, PlayerName);

        Close(true);
    }


}

void MAIN_Frame::OnClick_Bank_Window(wxCommandEvent& event){
    cout << "Bank Window Button Pressed" << endl;

        username_fetch = player_username->GetValue().ToStdString();
    if(mode_selected == -1 || username_fetch == "" || username_fetch == " "){
        wxMessageBox("Please Select Game Mode and Username!\n",
                     "Setup Incomplete", wxOK | wxICON_INFORMATION);
    }else{
        Bank_Window = new BANK_Frame("", wxPoint(50, 50), wxSize(450, 640));
        Bank_Window->Center();
        Bank_Window->Show(true);
        // Bank_Window->send_data(mode_selected, PlayerName);

        Close(true);
    }

    
}