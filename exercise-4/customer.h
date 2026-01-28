#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "bankaccount.h"
#include "creditaccount.h"
#include <string>

class Customer
{
public:
    Customer(std::string ownerName, double creditAmount);
    std::string getName();
    void showBalance();
    bool deposit(double);
    bool withdraw(double);
    bool creditDeposit(double);
    bool creditWithdraw(double);


private:
    std::string name;
    BankAccount *currentAccount;
    CreditAccount *creditAccount;

};

#endif // CUSTOMER_H
