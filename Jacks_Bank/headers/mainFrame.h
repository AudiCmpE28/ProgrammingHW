#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include <wx/wx.h>
#include <wx/textctrl.h>

#include <wx/slider.h> // slider 
#include <wx/tglbtn.h> // toggle button

/*to not include class and cause infinite repetition*/
class GAME_Frame; 
class BANK_Frame;

/*Main Class for MAIN_Frame*/
class MAIN_Frame : public wxFrame {
  public:
    MAIN_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    
  private:
    GAME_Frame* Game_Window;
    BANK_Frame* Bank_Window;

    //menu on top bar
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);


////////////// SET UP //////////////////////
/* Window Layout */
    wxBoxSizer* window_layout;

/* Title // Subtitles */
    wxStaticText *heading;

/* Button for Modes */
    //Button variables
    wxBoxSizer* setup_box_config;
    wxButton* setup_button_config;
    
    //Mode Selected
    wxStaticText *mode_display;
    int mode_selected;

    /*Wallet*/
    wxStaticText *wallet;
    wxBoxSizer* Wallet_Display;

/* Choose Window to Go to */
    // Button variable
    wxBoxSizer* window_box_config;
    wxButton* window_button_config;
    // button functions
    void OnClick_Game_Window(wxCommandEvent& event);
    void OnClick_Bank_Window(wxCommandEvent& event);



// /* slider for amounf of rounds*/
//     int fill;
//     wxStaticText *roundNum;
//     wxSlider *slider;
//     void OnScroll(wxScrollEvent& event);


    wxDECLARE_EVENT_TABLE();
};

// class Slider : public wxFrame {
//     public:
//         Slider(const wxString& title);
// };

enum id_numbers{
    ID_SLIDER = 5,
    ID_player_name = 8
};
 
enum button_ids{
    ID_easy_button = 10,
    ID_medium_button = 11,
    ID_expert_button = 12,
    ID_game_button = 20,
    ID_bank_button = 21
};
 

#endif /* MAINFRAME_H_ */