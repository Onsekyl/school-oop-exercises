#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

using namespace std;

class BankAccount
{
public:
    BankAccount(string newOwner);
    double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);

protected:
    string owner;
    double balance = 0;

};

#endif // BANKACCOUNT_H
