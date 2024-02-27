#ifndef IBANK_H
#define IBANK_H

#include <string>
class Ibank
{
    public:
    virtual ~Ibank(){}
    virtual void deposit(int accountId, double amount) = 0;
    virtual void withdraw(int accountId, double amount) = 0;
    virtual double getBalance(int accountId)  = 0;
    
    protected:
    virtual void createAccount(int accountId, std::string &name) = 0;
    virtual void deleteAccount(int accountId) = 0;
};

#endif