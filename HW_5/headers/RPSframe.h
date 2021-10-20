#ifndef RPSFRAME_H_
#define RPSFRAME_H_


#include <wx/wx.h>
#include <string.h>

using std::string;

class cGame : public wxFrame
{
public:
    cGame(const wxString& windowTitle);
    ~cGame();

    void config_game(int rounds, int cpuChoice);

private:
    

};

#endif /* RPSFRAME_H_ */
