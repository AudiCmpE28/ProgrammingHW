#ifndef BANK_H
#define BANK_H

class Bank {
private:
    double balance;

public:
    Bank();
    void deposit(double cash);
    bool withdraw(double cash);
    double getBalance();
};



#endif /* BANK_H */