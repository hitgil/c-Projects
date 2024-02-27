#ifndef ADMIN_H
#define ADMIN_H

#include "./IAdmin.h"

class Admin : public Person, public IAdmin
{
    int adminId;

public:
    Admin(std::string adminName, int adminId);
    // void enterAdminDetails();
    int getAdminId();
    std::string getAdminName() override;
    bool createUser(Bank &bank,std::string userName,int userId) override;

    bool deleteUser(Bank &bank,std::string userName,int userId) override;
};

#endif
