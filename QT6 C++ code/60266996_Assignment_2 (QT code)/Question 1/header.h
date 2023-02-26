#ifndef HEADER_H
#define HEADER_H
#include <QString>
#include <QList>
#include <QDate>

#endif // HEADER_H



class Customer {
private:
    QString m_Name;
    QString m_Id;

public:
    Customer(QString name, QString ID);
    QString toString();
};



class Transaction {
private:
    QString m_Description;
    QDate m_Date;

public:
    Transaction(QString customer, QDate date);
    QString toString();
    QDate getDate();

};



class Account {
private:
    QString m_AccountNo;
    Customer m_AccHolder;


public:
    double m_Balance=0;
    QList <Transaction> m_Transactions;
    Account (QString account, Customer cust);
    void deposit (double d_amt);
    bool withdraw (double w_amt);
    QString toString();
    QList<Transaction> getTransactions();
    double getBalance();
    void setBalance(double new_balance);
    QString getAccountNo();


};

class Savings : public Account {
private:

public:

    double Interest = 0.04;
    Savings (QString account, Customer cust);
    bool withdraw (double w_amt);
    QString toString();


};

class Cheque : public Account {
private:

    double m_Overdraft;
public:

    Cheque (QString account, Customer cust, double ovd);
    bool withdraw (double w_amt);
    QString toString();


};


class AccountList {
private:

public:

//    QList<QSharedPointer<Account>> accountList;
    QList<Account*> list;

    void addAccount(Account* account);
    void displayList();
    void displayAccounts (QDate date);
    int countAccounts (double d);
    void deleteAll();

};

//struct AccountPointerList {
//    QList<Account*> accountList; // put into class

//};


