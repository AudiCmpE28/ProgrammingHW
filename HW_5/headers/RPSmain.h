#ifndef RPSAPP_H_
#define RPSAPP_H_

#include <wx/wx.h>
#include <string.h>
#include "RPSframe.h"

using std::string;

class cMain : public wxFrame
{
public:
    cMain(const wxString& windowTitle);
    ~cMain();

    // -------------Menu Event Handlers---------
    /**
     * Event handler for the Instruction menu item.
     * @param event the item selection event.
     */
    void on_instruction(wxCommandEvent& event);

    /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
    void on_quit(wxCommandEvent& event);

    // ------------Button Event Handlers---------
    void on_random(wxCommandEvent& event);
    void on_smart(wxCommandEvent& event);
    void on_genius(wxCommandEvent& event);

    // ------------Slider Event Handler----------
    void on_slider(wxCommandEvent& event);

    // ------------Submit Event Handler----------
    void on_submit(wxCommandEvent& event);

private:
    cGame *game_frame;
    int CPU_Selection;
    int maxRounds;

    wxSlider *slider;
    wxStaticText *chosen_button_name;
    wxStaticText *roundNum;

    wxDECLARE_EVENT_TABLE();

    void init_menu_bar();

    void init_main_pannel();

    void update_button_choice_text(string choice, int cpuChoice);

    void update_slider_selection_text(int rounds);
};

enum
{
    RPS_Instruction = wxID_ABOUT,
    RPS_Quit  = wxID_EXIT
};

#endif /* RPSAPP_H_ */
