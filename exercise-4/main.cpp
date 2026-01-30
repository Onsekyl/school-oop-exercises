#include "customer.h"
#include "creditaccount.h"
#include "bankaccount.h"
#include <iostream>

using namespace std;

int main()
{
    // Customer(s) test
    Customer customer1("Albert", 1200);
    customer1.getName();
    customer1.creditWithdraw(400.66);
    customer1.deposit(402);
    customer1.showBalance();
    customer1.creditWithdraw(800);
    customer1.withdraw(341.32);
    customer1.showBalance();
    customer1.creditDeposit(1023.07);
    customer1.showBalance();
    customer1.creditWithdraw(-324.34);
    customer1.deposit(-65.45);
    customer1.showBalance();

    Customer customer2("Mona", 800);
    customer2.showBalance();
    customer1.deposit(432.32);
    customer1.wireTransfer(432.32, customer2);
    customer2.showBalance();
    customer2.wireTransfer(440, customer1);
    customer2.wireTransfer(-240.67, customer1);
    customer2.showBalance();
    customer1.showBalance();
    customer2.wireTransfer(240.67, customer1);
    customer2.showBalance();
    customer1.showBalance();

    /*
    // BankAccount and CreditAccount test
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
    */

    return 0;
}
