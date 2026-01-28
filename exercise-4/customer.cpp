#include "customer.h"
#include "creditaccount.h"
#include "bankaccount.h"
#include <iostream>

using namespace std;

Customer::Customer(string ownerName, double creditAmount)
{
    name = ownerName;
    currentAccount = new BankAccount(name);
    creditAccount = new CreditAccount(name, creditAmount);
}

string Customer::getName()
{

}

void Customer::showBalance()
{

}

bool Customer::deposit(double)
{

}

bool Customer::withdraw(double)
{

}

bool Customer::creditDeposit(double)
{

}

bool Customer::creditWithdraw(double)
{

}
