#include <wx/wx.h>
#include "headers/mainFrame.h" //other class
#include "headers/appInit.h"

using namespace std;

bool App_Init::OnInit(){
    cout << "OnInit: Initializing Jack's Black" << endl;

    MAIN_Frame *SetUpFrame = new MAIN_Frame("Initial Configuration", wxPoint(50, 50), wxSize(750, 840));
    SetUpFrame->Center();
    SetUpFrame->Show(true);

    return true;
}

// Create a new application object.
wxIMPLEMENT_APP(App_Init);