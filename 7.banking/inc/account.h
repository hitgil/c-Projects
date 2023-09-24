// account.h
#pragma once

#include <ctime>

class Account
{
private:
    int accountNumber;
    double balance;
    int pin;
    bool locked;
    time_t lastAccessTime;

public:
    Account(int accNumber, int pin);
    int getAccountNumber();
    double getBalance();
    bool isLocked();
    bool checkPin(int enteredPin);
    void deposit(double amount);
    bool withdraw(double amount);
    void lockAccount();
    void unlockAccount();
    void checkAccountStatus();
};
