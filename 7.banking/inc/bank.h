#ifndef BANK_H
#define BANK_H

#include "Ibank.h"
#include <string>

class Bank : public Ibank
{
private:
    static const int MAX_ACCOUNTS = 100;

    struct Account
    {
        int accountId;
        std::string name;
        double balance;
        bool isActive;

        Account() : accountId(-1), balance(0.0), isActive(false) {}
    };

    Account accounts[MAX_ACCOUNTS];


    int findAccountIndex(int accountId);

public:
    bool doesUserExist(int userId);
    void deposit(int accountId, double amount) override;
    void withdraw(int accountId, double amount) override;
    double getBalance(int accountId)  override;
    void createAccount(int accountId,  std::string &name) override;
    void deleteAccount(int accountId) override;
};

#endif 
