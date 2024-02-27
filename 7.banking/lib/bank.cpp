#include "../inc/bank.h"
#include <iostream>


int Bank::findAccountIndex(int accountId)
{
    for (int index = 0; index < MAX_ACCOUNTS; index++)
    {
        if (accounts[index].isActive && accounts[index].accountId == accountId)
        {
            return index;
        }
    }
    return -1;
}

bool Bank::doesUserExist(int userId)
{
    return findAccountIndex(userId) != -1;
}

void Bank::deposit(int accountId, double amount)
{
    int index = findAccountIndex(accountId);
    if (index != -1)
    {
        accounts[index].balance += amount;
    }
    else
    {
        std::cerr << "Error: Account not found for deposit.\n";
    }
}

void Bank::withdraw(int accountId, double amount)
{
    int index = findAccountIndex(accountId);
    if (index != -1)
    {
        if (accounts[index].balance >= amount)
        {
            accounts[index].balance -= amount;
        }
        else
        {
            std::cerr << "Error: Insufficient funds for withdrawal.\n";
        }
    }
    else
    {
        std::cerr << "Error: Account not found for withdrawal.\n";
    }
}

double Bank::getBalance(int accountId)
{
    int index = findAccountIndex(accountId);
    if (index != -1)
    {
        return accounts[index].balance;
    }
    else
    {
        std::cerr << "Error: Account not found while checking balance.\n";
        return -1;
    }
}

void Bank::createAccount(int accountId, std::string &name)
{
    int index = findAccountIndex(accountId);
    if (index == -1)
    {
        for (int i = 0; i < MAX_ACCOUNTS; ++i)
        {
            if (!accounts[i].isActive)
            {
                accounts[i].accountId = accountId;
                accounts[i].name = name;
                accounts[i].balance = 0.0;
                accounts[i].isActive = true;
                return;
            }
        }
        std::cerr << "Error: Bank account limit reached.\n";
    }
    else
    {
        std::cerr << "Error: Account already exists.\n";
    }
}

void Bank::deleteAccount(int accountId)
{
    int index = findAccountIndex(accountId);
    if (index != -1)
    {
        accounts[index].isActive = false;
    }
    else
    {
        std::cerr << "Error: Account not found for deletion.\n";
    }
}
