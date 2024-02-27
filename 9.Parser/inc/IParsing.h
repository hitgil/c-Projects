#ifndef IPARSING_H
#define IPARSING_H

#include <iostream>
#include <fstream>
#include <string>

class IParsing
{

public:
    virtual ~IParsing() {}
    virtual void parse(const std::string &filename) = 0;
};

#endif