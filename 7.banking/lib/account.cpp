#include "account.h"
#include <iostream>

Account::Account(int accNumber, int pin)
{
    accountNumber = accNumber;
    balance = 0.0;
    this->pin = pin;
    locked = false;
    lastAccessTime = time(nullptr);
}

int Account::getAccountNumber()
{
    return accountNumber;
}

double Account::getBalance()
{
    return balance;
}

bool Account::isLocked()
{
    return locked;
}

bool Account::checkPin(int enteredPin)
{
    if (locked)
    {
        std::cout << "Account is locked. Please contact customer support." << std::endl;
        return false;
    }
    if (enteredPin == pin)
    {
        lastAccessTime = time(nullptr);
        return true;
    }
    return false;
}

void Account::deposit(double amount)
{
    balance += amount;
}

bool Account::withdraw(double amount)
{
    if (locked)
    {
        std::cout << "Account is locked. Please contact customer support." << std::endl;
        return false;
    }
    if (balance >= amount)
    {
        balance -= amount;
        return true;
    }
    else
    {
        std::cout << "Insufficient balance." << std::endl;
        return false;
    }
}

void Account::lockAccount()
{
    locked = true;
    std::cout << "Account locked. Please contact customer support." << std::endl;
}

void Account::unlockAccount()
{
    locked = false;
    std::cout << "Account unlocked." << std::endl;
}

void Account::checkAccountStatus()
{
    time_t currentTime = time(nullptr);
    if (locked && (currentTime - lastAccessTime) >= 300)
    {
        lockAccount();
    }
}
