#include "headers/RPSmain.h"
#include "headers/RPSframe.h"
#include "wx/sizer.h"
#include "icons/slider.xpm"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
// Link Menu Button IDs with corresponding event handler function
    EVT_MENU(RPS_Instruction, cMain::on_instruction) 
    EVT_MENU(RPS_Quit,  cMain::on_quit)
wxEND_EVENT_TABLE()

cMain::cMain(const wxString& windowTitle) : wxFrame(nullptr, wxID_ANY, windowTitle, wxPoint(30, 30), wxSize(500, 600))
{
    CPU_Selection = 1;
    maxRounds = 20;
    init_menu_bar();
    init_main_pannel();
}

cMain::~cMain()
{
}

// --------------------- MENU BAR ---------------------------------
void cMain::init_menu_bar()
{
    // Create a "File" Menu
    wxMenu *fileMenu = new wxMenu;
    // Add an Exit option into the "File" menu
    fileMenu->Append(RPS_Quit,  "&Exit\tAlt-X", "Quit program");

    // Create the "Help"
    wxMenu *helpMenu = new wxMenu;
    // Add a About option into the "Help menu"
    helpMenu->Append(RPS_Instruction, "&Instructions\tF1",   "Show Instructions dialog");

    // Create the actual Menu Bar
    wxMenuBar *menuBar = new wxMenuBar();
    // Append both the "File" menu and a "Help" menu into the bar
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar); // Set the bar itself
}
// on click menu event handler functions:
void cMain::on_instruction(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "Welcome to Rock Paper Scissors!\n"
                    "Select which CPU you would like to play against\n"
                    "Then select how many rounds you would like to play!"
                ),
                "Instructions",
                wxOK | wxICON_INFORMATION,
                this);
}

void cMain::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}

// --------------------- END OF MENU BAR ---------------------------------

// --------------------- Main Screen ---------------------------------

void cMain::init_main_pannel() 
{
    // Make the sizer for the entire screen 
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    // Instruction Text
    wxFont inst_font(12, wxDEFAULT, wxNORMAL, wxBOLD);
    wxStaticText *instruction = new wxStaticText(this, wxID_ANY, wxT("Choose a CPU!"), wxPoint(50, 15));
    instruction->SetFont(inst_font);


    // Button panel
    // Create a new button Panel with a horizontal box sizer
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    // Create text and 3 buttons
    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 wxT("Choose:"));
    wxButton *random_button = new wxButton(button_panel, wxID_ANY, "RandomCPU");
    wxButton *smart_button  = new wxButton(button_panel, wxID_ANY, "SmartCPU");
    wxButton *genius_button = new wxButton(button_panel, wxID_ANY, "GeniusCPU");

    // Bind the buttons to an event function
    random_button->Bind (wxEVT_BUTTON, &cMain::on_random, this);
    smart_button->Bind  (wxEVT_BUTTON, &cMain::on_smart, this);
    genius_button->Bind (wxEVT_BUTTON, &cMain::on_genius, this);

    // Add elements to the button sizer
    button_sizer->Add(choose_text, 0, wxALIGN_CENTER_VERTICAL, 15);
    // Param: button, proportion, wxRIGHT/wxLEFT/wxALL (where the borders apply), how much room
    // In this case, it's 15 pixels to the right for space
    button_sizer->Add(random_button, 0, wxRIGHT, 15); 
    button_sizer->Add(smart_button, 0, wxRIGHT, 15);
    button_sizer->Add(genius_button, 0, wxRIGHT, 15);
    // Set sizer element for the button panel
    button_panel->SetSizer(button_sizer);


    // Choice panel
    wxPanel *choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choice_sizer = new wxGridSizer(2, 0, 10);

    wxStaticText *chosen_object_label =
            new wxStaticText(choice_panel, wxID_ANY, "Chosen CPU:");
    chosen_button_name = new wxStaticText(choice_panel, wxID_ANY, "Random CPU");
    //chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    // Add choice panel elements
    choice_sizer->Add(chosen_object_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(chosen_button_name, 0, 0, 0);
    // Set sizer for choice panel
    choice_panel->SetSizer(choice_sizer);


    // Slider Round Selection Panel
    wxPanel *slider_panel = new wxPanel(this, wxID_ANY);
    wxSizer *slider_sizer = new wxBoxSizer(wxVERTICAL);
    // Slider Header
    wxFont header_font(12, wxDEFAULT, wxNORMAL, wxBOLD);
    wxStaticText *slider_header = new wxStaticText(slider_panel, wxID_ANY, wxT("Rounds Playing:"), wxPoint(50, 15));
    slider_header->SetFont(header_font);
    // Slider itself
    slider = new wxSlider(slider_panel, wxID_ANY, 20, 1, 20, wxDefaultPosition, wxSize(200, -1), wxSL_HORIZONTAL);
    slider->Bind(wxEVT_COMMAND_SLIDER_UPDATED, &cMain::on_slider, this);
    // Add slider panel elements
    slider_sizer->Add(slider_header, 0, wxALIGN_CENTER);
    slider_sizer->AddSpacer(5);
    slider_sizer->Add(slider, 0, 0, 0);
    slider_panel->SetSizer(slider_sizer);
    // Round Text panel
    wxPanel *roundText_panel = new wxPanel(this, wxID_ANY);
    wxSizer *roundText_sizer = new wxGridSizer(2, 0, 10);

    wxStaticText *roundSelect_label =
            new wxStaticText(roundText_panel, wxID_ANY, "Rounds Playing:");
    roundNum = new wxStaticText(roundText_panel, wxID_ANY, "20");
    //chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    // Add choice panel elements
    roundText_sizer->Add(roundSelect_label, 0, wxALIGN_RIGHT, 0);
    roundText_sizer->Add(roundNum, 0, 0, 0);
    // Set sizer for choice panel
    roundText_panel->SetSizer(roundText_sizer);

    // Submit Button
    wxButton *submit = new wxButton(this, wxID_ANY, "Start Game!");
    submit->Bind (wxEVT_BUTTON, &cMain::on_submit, this);

    // Main panel
    // Add main panel element and spacers
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(instruction, 0, wxALIGN_CENTER, 0); //addFunct, porportion, flag, postion
    main_panel_sizer->AddSpacer(5);
    main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(slider_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(roundText_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(50);
    main_panel_sizer->Add(submit, 0, wxALIGN_CENTER, 0);

    SetSizer(main_panel_sizer);
}

// Event handlers for buttons and display selection
void cMain::on_random(wxCommandEvent& event)
{
    update_button_choice_text("Random CPU", 1);
}

void cMain::on_smart(wxCommandEvent& event)
{
    update_button_choice_text("Smart CPU", 2);
}

void cMain::on_genius(wxCommandEvent& event)
{
    update_button_choice_text("Genius CPU", 3);
}

void cMain::update_button_choice_text(string choice, int cpuChoice)
{
    chosen_button_name->SetLabelText(choice);
    CPU_Selection = cpuChoice;
}

void cMain::on_slider(wxCommandEvent& event)
{
    update_slider_selection_text(slider->GetValue());
}

void cMain::on_submit(wxCommandEvent& event)
{
     game_frame = new cGame("Rock Paper Scissors Game");
     game_frame->Show(true);
     game_frame->config_game(maxRounds, CPU_Selection);
     Close(true);
}

void cMain::update_slider_selection_text(int rounds)
{
    roundNum->SetLabelText(std::to_string(rounds));
    maxRounds = rounds;
}

// --------------End of Main Screen-----------------