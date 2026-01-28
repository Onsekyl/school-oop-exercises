#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "bankaccount.h"
#include <string>

class CreditAccount : public BankAccount
{
public:
    CreditAccount(std::string newOwner, double creditAmount);
    bool deposit(double) override;
    bool withdraw(double) override;

protected:
    double creditLimit = 0;
};

#endif // CREDITACCOUNT_H
