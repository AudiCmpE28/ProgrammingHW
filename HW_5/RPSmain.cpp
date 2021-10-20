#include <wx/wx.h>
#include "headers/RPSmain.h"
#include "headers/RPSsetup.h"

#include <iostream>
#include "headers/Game.h"
#include "headers/ChooserFactory.h"
#include <time.h>

using namespace std;


bool RPS_App::OnInit(){
    cout << "OnInit: Initializing Rock-Paper-Scissors" << endl;

    RPS_Setup *SetUpFrame = new RPS_Setup("Initial Configuration", wxPoint(50, 50), wxSize(450, 640));
    SetUpFrame->Center();
    SetUpFrame->Show(true);

    return true;
}

// Create a new application object.
wxIMPLEMENT_APP(RPS_App);