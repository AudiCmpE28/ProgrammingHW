#include <wx/wx.h>
#include "headers/RPSframe.h"

cGame::cGame(const wxString& windowTitle) : wxFrame(nullptr, wxID_ANY, windowTitle, wxPoint(30, 30), wxSize(500, 600))
{

}

cGame::~cGame()
{
}

void cGame::config_game(int rounds, int cpuChoice) {
    int lol = rounds;
    int lol2 = cpuChoice;
}