#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
public:
    BankAccount(std::string newOwner);
    double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);

protected:
    std::string owner;
    double balance = 0;

};

#endif // BANKACCOUNT_H
