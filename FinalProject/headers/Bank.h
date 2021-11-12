#include <vector>
#include <string>
#include <ctime>

#ifndef HAND_H_
#define HAND_H_
using std::vector;
using std::string;
using std::strftime;

struct TX{
    double Balance;
    string Time;
};
class Bank {
    private:
    void writeTX(double money){
        TX newTX;
        char datestr[100];
        time_t current_T;
        tm * curr_tm;
        time(&current_T);
        strftime(datestr,100,"%B %d, %Y %T",curr_tm);
        
        newTX.Balance=money;
        newTX.Time=datestr;
        Transactions.push_back(newTX);
    }
    double Balance;
    vector<TX> Transactions;
    
    public:
    void deposit(double money);
    void withdraw(double money);
    double displayBalance();
    vector<double> displayTransactions();

};
#endif
