#ifndef APPINIT_H_
#define APPINIT_H_

#include <iostream>
#include <wx/wx.h>

using namespace std;

class App_Init: public wxApp {
    public:
        virtual bool OnInit() override;
};

#endif /* APPINIT_H_ */
