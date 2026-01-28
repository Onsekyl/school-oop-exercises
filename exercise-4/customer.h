#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "creditaccount.h"

using namespace std;

class Customer
{
public:
    Customer(string ownerName, double creditAmount);
    string getName();
    void showBalance();
    bool deposit(double);
    bool withdraw(double);
    bool creditDeposit(double);
    bool creditWithdraw(double);


private:
    string name;
    BankAccount currentAccount;
    CreditAccount creditAccount;

};

#endif // CUSTOMER_H
