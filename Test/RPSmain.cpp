#include <wx/wx.h>
#include "headers/RPSmain.h"
#include "headers/RPSframe.h"
#include "headers/RPSsetup.h"

using namespace std;


bool RPS_App::OnInit(){
    cout << "OnInit: Initializing Rock-Paper-Scissors" << endl;


    RPS_Frame *frame1 = new RPS_Frame("Rock-Paper-Scissors", wxPoint(50, 50), wxSize(450, 640));
    frame1->Center();
    frame1->Show(true);
    // frame1->Hide();

    // RPS_Setup *frame2 = new RPS_Setup("Rock-Paper-Scissors-configure", wxPoint(50, 50), wxSize(450, 640));
    // frame2->Center();
    // frame2->Show(true);
    // button->Hide();

    return true;
}

// Create a new application object.
wxIMPLEMENT_APP(RPS_App);