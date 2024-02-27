#include "../inc/Person.h"

std::string Person::getName()
{
    return name;
}
void Person::setName(const std::string &NewName)
{
    name = NewName;
}