#ifndef ADMIN_H
#define ADMIN_H

#include "Iadmin.h"
#include "Iuser.h"
#include "person.h"
#include "bank.h"
#include <string>

class Admin : virtual public Person, public Iadmin
{
private:
    Bank &bank;

public:
    Admin(const std::string &name, Bank &bank);
    void createUser(int userId, std::string &userName) override;
    void deleteUser(int userId) override;
};

#endif 
