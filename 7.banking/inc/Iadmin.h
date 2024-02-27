#ifndef IADMIN_H
#define IADMIN_H
#include <string>
class Iadmin
{
public:
    virtual ~Iadmin() {}
    virtual void createUser(int userId, std::string &userName) = 0;
    virtual void deleteUser(int userId) = 0;
};

#endif 
