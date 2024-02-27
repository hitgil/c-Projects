#ifndef PERSON_H
#define PERSON_H

#include "./Iperson.h"
#include <string>

class Person : public IPerson {
protected:
    std::string name;

public:
    Person(const std::string &name);
    std::string getName() override;
};

#endif
