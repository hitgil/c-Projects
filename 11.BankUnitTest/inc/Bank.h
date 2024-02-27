#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <vector>
#include "./Admin.h"
#include "./IUser.h"

class Bank
{
private:
    struct Account
    {
        int accountId;
        std::string name;
        double balance;
        bool isActive;

        Account() : accountId(-1), balance(0.0), isActive(false) {}
    };

    std::vector<Account> accountsAdmin;
    std::vector<Account> userAccounts;
    virtual bool addUserToBankDB(int accountId, std::string &name);
    virtual bool deleteUserFromBankDB(int accountId, std::string &name);
    friend class Admin;
    // User &user;

public:
    Bank(){};
    virtual ~Bank(){};
    virtual bool validUser(int accountId, std::string &name);
    virtual bool depositToUserAccount(IUser &user, int amount);
    virtual bool withdrawFromUserAccount(IUser &user, int amount);
    virtual double getBalanceFromUserAccount(IUser &user);
    virtual void PrintBalanceFromUserAccount(IUser &user);
    virtual void displayAllUserDetails();
};

#endif
