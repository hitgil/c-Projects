#ifndef JSONPARSING_H
#define JSONPARSING_H
#include <iostream>
#include <jsoncpp/json/json.h>
#include "IParsing.h"

class JsonParsing : public IParsing
{
public:
    void parse(const std::string &filename) override;
};

#endif