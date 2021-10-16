#ifndef RPSFRAME_H_
#define RPSFRAME_H_

#include <wx/wx.h>

class RPS_Frame: public wxFrame
{
public:
    RPS_Frame(const wxString& title,
                    const wxPoint& pos, const wxSize& size);

private:
    void OnHello(wxCommandEvent& event);
    // void OnBonjour(wxCommandEvent& event);
    // void OnGutenTag(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    // void OnClick(wxCommandEvent& event);
    
    //Button set up for RPS
    wxBoxSizer* mainBox_config;
    wxButton* button_config;
    static const long idButtonRock;
    static const long idButtonPaper;
    static const long idButtonScissors;
    void OnClickRock(wxCommandEvent& event);
    void OnClickPaper(wxCommandEvent& event);
    void OnClickScissors(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_Hello    = 1
    // ID_Bonjour  = 2,
    // ID_GutenTag = 3
};

enum RPS_button{
    button1 = 1,
    button2 = 2,
    button3 = 3
};

#endif /* RPSFRAME_H_ */
