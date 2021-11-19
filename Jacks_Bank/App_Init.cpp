#include <wx/wx.h>
#include "headers/mainFrame.h" 
#include "headers/appInit.h"

//other class for testing fast
#include "headers/gameFrame.h"
#include "headers/bankFrame.h"


bool App_Init::OnInit(){
    cout << "OnInit: Initializing Jack's Black" << endl;
    
    /*MAIN window to be used in final version */
    MAIN_Frame *SetUpFrame = new MAIN_Frame("Initial Configuration", wxPoint(50, 50), wxSize(450, 640));
    SetUpFrame->Center();
    SetUpFrame->Show(true);

    /* Bank Window - Test1 */
    // BANK_Frame *SetUpFrame = new BANK_Frame("Initial Configuration", wxPoint(50, 50), wxSize(450, 640));
    // SetUpFrame->Center();
    // SetUpFrame->Show(true);

    /* Game Window - Test2 */
    // GAME_Frame *SetUpFrame = new GAME_Frame("Initial Configuration", wxPoint(50, 50), wxSize(450, 640));
    // SetUpFrame->Center();
    // SetUpFrame->Show(true);

    return true;
}

// Create a new application object.
wxIMPLEMENT_APP(App_Init);