#include "../inc/user.h"
#include "../inc/person.h"

User::User(const std::string &name, Bank &bank, int accountId)
    : Person(name), bank(bank), accountId(accountId) {}

void User::deposit(double amount)
{
     bank.deposit(accountId, amount);
}

void User::withdraw(double amount)
{
    bank.withdraw(accountId, amount);
}

double User::checkBalance()
{
    return bank.getBalance(accountId);
}
