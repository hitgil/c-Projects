#ifndef IUSER_H
#define IUSER_H

class Iuser
{

public:
    virtual ~Iuser() {}
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double checkBalance() = 0;
};

#endif