
#ifndef USER_H
#define USER_H

#include "person.h"
#include "Iuser.h"
#include "bank.h"

class User : virtual public Person, public Iuser
{
private:
    Bank &bank;
    int accountId;

public:
    User(const std::string &name, Bank &bank, int accountId);
    void deposit(double amount) override;
    void withdraw(double amount) override;
    double checkBalance() override;
};

#endif 