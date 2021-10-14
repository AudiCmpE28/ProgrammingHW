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

    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_Hello    = 1
    // ID_Bonjour  = 2,
    // ID_GutenTag = 3
};

#endif /* RPSFRAME_H_ */
