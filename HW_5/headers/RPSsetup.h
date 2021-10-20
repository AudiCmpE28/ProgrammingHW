#ifndef RPSSETUP_H_
#define RPSSETUP_H_

#include <wx/wx.h>
#include "RPSmain.h"

class cApp : public wxApp
{
public:
    cApp();
    ~cApp();

private:
    cMain* init_frame = nullptr;

public:
    virtual bool OnInit();

};


#endif /* RPSSETUP_H_ */