#include "../inc/admin.h"

Admin::Admin(const std::string &name, Bank &bank) : Person(name), bank(bank)
{
}

void Admin::createUser(int userId,  std::string &userName)
{
    bank.createAccount(userId, userName);
}

void Admin::deleteUser(int userId)
{
    bank.deleteAccount(userId);
}
