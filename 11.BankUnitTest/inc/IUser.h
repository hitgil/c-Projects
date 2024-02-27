#ifndef IUSER_H
#define IUSER_H
#include <iostream>
#include <string>

class IUser
{

public:
    virtual ~IUser() {}
    virtual std::string getUserName() = 0;
    virtual double depositAmount(int amount) = 0;
    virtual double withdrawAmount(int amount) = 0;
    virtual int getUserId()=0;
};

#endif