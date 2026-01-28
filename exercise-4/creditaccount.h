#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "bankaccount.h"

class CreditAccount : public BankAccount
{
public:
    CreditAccount(string newOwner, double creditAmount);
    bool deposit(double) override;
    bool withdraw(double) override;

protected:
    double creditLimit = 0;
};

#endif // CREDITACCOUNT_H
