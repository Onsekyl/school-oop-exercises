#include <iostream>
#include "creditaccount.h"

using namespace std;

int main()
{
    BankAccount bankAccount("Joni");
    bankAccount.deposit(200);
    bankAccount.deposit(-1);
    bankAccount.withdraw(38);
    bankAccount.getBalance();
    bankAccount.withdraw(-3);
    bankAccount.withdraw(200);
    bankAccount.getBalance();
    cout << '\n';

    CreditAccount creditAccount("Teresa", 1000);
    creditAccount.withdraw(-100);
    creditAccount.withdraw(550.71);
    creditAccount.getBalance();
    creditAccount.withdraw(449.30);
    creditAccount.withdraw(440.86);
    creditAccount.getBalance();
    creditAccount.deposit(200);
    creditAccount.deposit(-100);
    creditAccount.deposit(900);
    creditAccount.getBalance();

    return 0;
}
