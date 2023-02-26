#include "header.h"
#include <iostream>
#include <QTextStream>
#include <QString>
#include <QList>


Customer::Customer(QString name,QString ID){
    Customer::m_Name = name;
    Customer::m_Id = ID;
}


QString Customer::toString()
{
    QString returnString = "Name: " + Customer::m_Name + " ID: " + Customer::m_Id;
    return returnString;
}

Transaction::Transaction(QString m_Description, QDate m_Date) {

    Transaction::m_Description = m_Description;
    Transaction::m_Date = m_Date;
}


QString Transaction::toString()
{
    QString returnString = Transaction::m_Description + " " + Transaction::m_Date.toString("yyyy.MM.dd");
    return returnString;
}

QDate Transaction::getDate()
{
    return Transaction::m_Date;
}

//    Transaction(QString customer, QDate date);



Account::Account(QString account, Customer cust): m_AccountNo(account), m_AccHolder (cust) {
//    QList <Transaction> m_Transactions;
}

QString Account::toString()
{
    QString returnString = "Account number:  " + m_AccountNo + " Customer " + m_AccHolder.toString() + " Balance: " + QString::number(m_Balance,'f', 2);
    return returnString;
}

double Account::getBalance()
{
    return m_Balance;
}

QString Account::getAccountNo() {
return m_AccountNo;
}


void Account::deposit(double d_amt) {
    m_Balance += d_amt;
    Transaction Transaction ("deposit", QDate::currentDate());
    m_Transactions.append(Transaction);
//    foreach(class Transaction T,m_Transactions)
//       qDebug()<<T.toString();
}

QList<Transaction> Account::getTransactions(){

    foreach(class Transaction T,m_Transactions)
        qDebug()<<T.toString();

    return m_Transactions;
}

Savings::Savings (QString account, Customer cust):  Account(account,cust)  {
    Transaction Transaction ("open savings account", QDate::currentDate());
    Account::m_Transactions.append(Transaction);
}


bool Savings::withdraw (double w_amt)
{
//    qDebug() << QString::number(m_Balance,'f', 2);
    double new_balance = (m_Balance - w_amt);
//    qDebug() << QString::number(new_balance,'f', 2);

    if (new_balance >= 0)
{
    qDebug()<< "Withdrawal processing";
    Account::m_Balance = (new_balance);
    Transaction Transaction ("withdrawal", QDate::currentDate());
    Account::m_Transactions.append(Transaction);
    return 1;
}
    else
{
    qDebug()<< "Withdrawal denied -- insufficient funds";
    return 0;}
}



Cheque::Cheque (QString account, Customer cust, double ovd):  Account(account,cust), m_Overdraft(ovd)
{
    Transaction Transaction ("open Cheque account", QDate::currentDate());
    Account::m_Transactions.append(Transaction);
}


bool Cheque::withdraw (double w_amt)
{
//    qDebug() << QString::number(m_Balance,'f', 2);
    double new_balance = ((m_Balance + m_Overdraft) - w_amt);
//    qDebug() << QString::number(new_balance,'f', 2);

if (new_balance >= 0)
{
    qDebug()<< "Withdrawal processing";
    Account::m_Balance = (new_balance);
    Transaction Transaction ("withdrawal", QDate::currentDate());
    Account::m_Transactions.append(Transaction);
    return 1;
}
else
{
    qDebug()<< "Withdrawal denied -- insufficient funds";
    return 0;}
}

QString Cheque::toString()
{
    return Account::toString() + " Overdraft: " +  QString::number(m_Overdraft);
}


void AccountList::addAccount(Account* account) {

    list.append(account);

}

void AccountList::displayList(){

    foreach(class Account* T, list)
        qDebug()<<T->toString();

    qDebug()<< "End of list: No accounts to show.";

}


int AccountList::countAccounts (double d) {

    int num=0;
//    double x = Account::getBalance();
    foreach(class Account *T, list){
        if (T->m_Balance>d){
        num++;}
        }
    return num;
}


void AccountList::deleteAll(){

    if(!list.isEmpty())
{
//    qDeleteAll(list);
    list.clear();
    qDebug() << "All accounts cleared from account list.";
}

}




