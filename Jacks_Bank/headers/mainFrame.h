#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include <wx/wx.h>
#include <wx/slider.h> // slider 
#include <wx/tglbtn.h> // toggle button

class MAIN_Frame : public wxFrame {
  public:
    MAIN_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    
  private:
    //menu on top bar
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);


////////////// SET UP //////////////////////
/*Window setup*/
    wxBoxSizer* window_layout;

/*Title*/
    wxStaticText *heading;


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
    ID_SLIDER = 100,
};

 

#endif /* MAINFRAME_H_ */