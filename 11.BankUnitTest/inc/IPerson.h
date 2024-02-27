#ifndef IPERSON_H
#define IPERSON_H
#include <iostream>
#include <string>

class IPerson
{
public:
    virtual ~IPerson() {}
    virtual void setName(const std::string &NewName) = 0;
    virtual std::string getName() = 0;
};

#endif
