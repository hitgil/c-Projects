#include "../inc/bank.h"

Account *Bank::createAccount(int accNumber, int pin)
{
    Account newAccount(accNumber, pin);
    accounts.push_back(newAccount);
    return &accounts.back();
}

Account *Bank::findAccount(int accNumber)
{
    for (size_t i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getAccountNumber() == accNumber)
        {
            return &accounts[i];
        }
    }
    return nullptr;
}
