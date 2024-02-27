#ifndef IPERSON_H
#define IPERSON_H
#include <string>

class IPerson
{
public:
    virtual ~IPerson() {}
    virtual std::string getName() = 0;
};

#endif