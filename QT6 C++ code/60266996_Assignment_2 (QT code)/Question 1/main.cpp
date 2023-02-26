#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include "header.h"
#include <QString>
#include <QDate>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qDebug() <<"Creating and initializing customer classes... \n";

    Customer customer ("John", "101");
    Customer customer2 ("David", "102");
    Customer customer3 ("Ellis", "103");
    Customer customer4 ("Mike", "104");
    Customer customer5 ("Justin", "105");

    qDebug() << customer.toString();
    qDebug() << customer2.toString();
    qDebug() << customer3.toString();
    qDebug() << customer4.toString();
    qDebug() << customer5.toString();

    Account Account1 ("A001", customer);
    Account Account2 ("A002", customer2);
    Account Account3 ("A003", customer3);

    qDebug() << "\nTesting ACCOUNT member functions... ";
    qDebug() << "Account number: " << Account1.getAccountNo();
    qDebug() << "Depositing 2000 into account...";
    Account1.deposit(2000);
    qDebug() << "Balance: " << Account1.getBalance();
    qDebug() << "Transactions:";
    Account1.getTransactions();

    qDebug() << "\nTesting SAVINGS member functions... ";
    Savings Savings1 ("S001", customer4);

    Savings1.deposit(500.00);
    qDebug() << "Deposited 500, test withdrawal 600 then 300. Balance: " << Savings1.getBalance();

    Savings1.withdraw(600.00);
    Savings1.withdraw(300.00);
    qDebug() << "Transactions:";
    Savings1.getTransactions();

    qDebug() << "\nTesting CHEQUE member functions... ";

    Cheque Cheque1 ("C001", customer5, 300);
    qDebug() << Cheque1.toString();
    qDebug() << "Test withdraw 500 then 300";
    Cheque1.withdraw(500.00);
    Cheque1.withdraw(300.00);

    qDebug() << "\nTesting ACCOUNTLIST member functions... ";

    AccountList AccountList;
    AccountList.addAccount(&Savings1);
    AccountList.addAccount(&Account1);
    AccountList.addAccount(&Cheque1);
    AccountList.addAccount(&Account2);
    AccountList.addAccount(&Account3);
    AccountList.displayList();
    qDebug() << "Counting accounts with balance of more than 100";
    qDebug() << AccountList.countAccounts(100);
    AccountList.deleteAll();

    AccountList.displayList();


    return a.exec();
}
