#ifndef IADMIN_H
#define IADMIN_H
#include <string>
#include "./Bank.h"
#include "./Person.h"
class Bank;

class IAdmin
{
public:
    virtual ~IAdmin() {}
    virtual bool createUser(Bank &bank,std::string userName,int userId) = 0;
    virtual bool deleteUser(Bank &bank,std::string userName,int userId) = 0;
    virtual std::string getAdminName() = 0;
};

#endif
