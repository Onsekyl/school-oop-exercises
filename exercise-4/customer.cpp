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
    return name;
}

void Customer::showBalance()
{
    cout << '\n' << name << "'s account balances\nCurrent account: " << currentAccount->getBalance()
         << "\nCredit account: " << creditAccount->getBalance() << "\n\n";
}

bool Customer::deposit(double amount)
{
    bool wasDeposited = currentAccount->deposit(amount);
    return wasDeposited;
}

bool Customer::withdraw(double amount)
{
    bool wasWithdrawn = currentAccount->withdraw(amount);
    return wasWithdrawn;
}

bool Customer::creditDeposit(double amount)
{
    bool wasDeposited = creditAccount->deposit(amount);
    return wasDeposited;
}

bool Customer::creditWithdraw(double amount)
{
    bool wasWithdrawn = creditAccount->withdraw(amount);
    return wasWithdrawn;
}

bool Customer::wireTransfer(double amount, Customer &receiver)
{
    cout << "Transfering " << amount << " from " << name << " to " << receiver.name << ":\n";
    bool wasWithdrawn = withdraw(amount);
    bool wasTransferred = false;

    if (wasWithdrawn)
    {
        wasTransferred = receiver.deposit(amount);
    }

    return wasTransferred;
}
