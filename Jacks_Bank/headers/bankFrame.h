#ifndef BANKFRAME_H_
#define BANKFRAME_H_

#include <iostream>
#include <wx/wx.h>
#include <wx/textctrl.h>

class BANK_Frame : public wxFrame {
  public:
    BANK_Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
    
  private:
    //menu on top bar
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    /*Window setup*/
    wxBoxSizer* window_layout;

    /*Title*/
    wxStaticText *heading;

    /*Total Balance*/
    wxBoxSizer* ATM_Display;
    wxStaticText *total_balance;

    /*Wallet*/
    wxStaticText *wallet;
    wxBoxSizer* Wallet_Display;
    
    /* Enter Amount to... */
    wxTextCtrl* amount_entered;
    std::string bank_fetch;
    
    //to add buttons for deposit and withdraw
    wxBoxSizer* button_config;
    wxButton* setup_button_config;

    /*Bank Deposit*/
    void OnClick_Deposit(wxCommandEvent& event);

    /*Bank Withdraw*/
    void OnClick_Withdraw(wxCommandEvent& event);

    /*Return button*/
    void OnClick_Return(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum atm_id{
  ID_bank_deposit = 60,
  ID_bank_withdraw = 61,
  ID_return = 62
};

#endif /* BANKFRAME_H_ */