#include "bankaccount.h"

BankAccount::BankAccount(string newOwner)
{
    owner = newOwner;
    cout << "[BANKACCOUNT CONSTRUCTOR] - New bank account with an owner name: " << owner << '\n';
}

double BankAccount::getBalance()
{
    cout << owner << "'s account's getBalance called. Balance: " << balance << '\n';
    return balance;
}

bool BankAccount::deposit(double depositAmount)
{
    bool wasDeposited = false;

    if (depositAmount > 0)
    {
        balance += depositAmount;
        wasDeposited = true;
    }

    cout << "Tried to deposit " << depositAmount << " to " << owner << "'s bank account, the deposit "
         << string(wasDeposited ? "was successful" : "failed") << '\n';

    return wasDeposited;
}

bool BankAccount::withdraw(double withdrawAmount)
{
    bool wasWithdrawn = false;

    if (balance - withdrawAmount >= 0 && withdrawAmount > 0)
    {
        balance -= withdrawAmount;
        wasWithdrawn = true;
    }

    cout << "Tried to withdraw " << withdrawAmount << " from " << owner << "'s bank account, the withdraw "
         << string(wasWithdrawn ? "was successful" : "failed") << '\n';

    return wasWithdrawn;
}
