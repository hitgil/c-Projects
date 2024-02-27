#include "../inc/person.h"

Person::Person(const std::string &name) : name(name) {
}

std::string Person::getName() {
    return name;
}

