#include <wx/wx.h>
#include "headers/RPSmain.h"
#include "headers/RPSframe.h"

using namespace std;

bool RPS_App::OnInit(){
    cout << "OnInit: Initializing Rock-Paper-Scissors" << endl;

    RPS_Frame *frame = new RPS_Frame("Rock-Paper-Scissors", wxPoint(50, 50), wxSize(450, 640) );
    frame->Show(true);
    
    return true;
}



// Create a new application object.
wxIMPLEMENT_APP(RPS_App);
