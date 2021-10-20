#include <wx/wx.h>
#include "headers/RPSsetup.h"

// Tells the entry point of the app (basically main)
wxIMPLEMENT_APP(cApp);

cApp::cApp() 
{

}

cApp::~cApp()
{

}

bool cApp::OnInit()
{
    init_frame = new cMain("Initialize The Game");
    init_frame->Show();
    return true;
}