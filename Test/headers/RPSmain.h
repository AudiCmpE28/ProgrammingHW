#ifndef RPSAPP_H_
#define RPSAPP_H_

#include <iostream>
#include <wx/wx.h>

using namespace std;

class RPS_App: public wxApp {
public:
    virtual bool OnInit() override;
};

#endif /* RPSAPP_H_ */
