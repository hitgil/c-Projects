#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "./IUser.h"
#include "./Person.h"

class User : public IUser, public Person
{
    int userId;

public:
    User(std::string userName, int userId) : Person(userName), userId(userId){};
    // void enterUserDetails();
    int getUserId() override;
    std::string getUserName() override;
    double depositAmount(int amount) override;
    double withdrawAmount(int amount) override;
    void print(){};
};

#endif