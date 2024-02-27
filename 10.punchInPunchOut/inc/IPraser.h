#ifndef IPRASER_H
#define IPRASER_H

#include "iostream"
#include "string"
class IParser
{
public:
    virtual ~IParser() {}
    virtual void parse(const std::string &filename) = 0;
};
#endif