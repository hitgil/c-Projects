// bank.h
#pragma once

#include "account.h"
#include <vector>

class Bank
{
private:
    std::vector<Account> accounts;

public:
    Account *createAccount(int accNumber, int pin);
    Account *findAccount(int accNumber);
};
