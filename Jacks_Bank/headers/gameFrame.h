#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include <iostream>
#include <wx/wx.h>

class GAME_Frame : public wxFrame {
  public:
    GAME_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    
  private:
    //menu on top bar
    // void OnRestart(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    /*Window setup*/
    wxBoxSizer* window_layout;

    /*Title*/
    wxStaticText *heading;

    wxDECLARE_EVENT_TABLE();
};

enum id_nums{
    ID_RestartGame = 30
};

#endif /* GAMEFRAME_H_ */