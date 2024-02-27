#ifndef PERSON_H
#define PERSON_H
#include "./IPerson.h"

class Person : public IPerson
{
private:
    std::string name;

public:
    Person(std::string name) : name(name){};
    void setName(const std::string &NewName) override;
    std::string getName() override;
};

#endif
