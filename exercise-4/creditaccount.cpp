#include "creditaccount.h"
#include "bankaccount.h"
#include <iostream>

using namespace std;

CreditAccount::CreditAccount(string newOwner, double creditAmount) : BankAccount(newOwner)
{
    creditLimit = creditAmount;
    cout << "[CREDIACCOUNT CONSTRUCTOR] - New credit account with an owner name: " << owner
         << " and credit limit of " << creditLimit << '\n';
}

bool CreditAccount::deposit(double depositAmount)
{
    bool wasDeposited = false;
    bool wasOverDeposit = false;
    double overDepositAmount;

    if (depositAmount > 0)
    {
        balance += depositAmount;
        wasDeposited = true;
    }

    if (balance > 0)
    {
        overDepositAmount = balance;
        balance = 0;
        wasOverDeposit = true;
    }

    cout << "Tried to deposit " << depositAmount << " to " << owner << "'s credit account, the deposit "
         << string(wasDeposited ? "was successful" : "failed");

    if (wasOverDeposit)
    {
        cout << ". The deposited amount exceeded the debt by " << overDepositAmount << " which should be refunded";
    }

    cout << '\n';

    return wasDeposited;
}

bool CreditAccount::withdraw(double withdrawAmount)
{
    bool wasWithdrawn = false;

    if (balance - withdrawAmount >= -creditLimit && withdrawAmount > 0)
    {
        balance -= withdrawAmount;
        wasWithdrawn = true;
    }

    cout << "Tried to withdraw " << withdrawAmount << " from " << owner << "'s credit account, the withdraw "
         << string(wasWithdrawn ? "was successful" : "failed") << '\n';

    return wasWithdrawn;
}
