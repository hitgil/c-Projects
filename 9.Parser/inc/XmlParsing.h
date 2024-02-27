#ifndef XMLPARSING_H
#define XMLPARSING_H
#include "IParsing.h"

class XmlParsing : public IParsing
{
public:
    void parse(const std::string &filename) override;
};

#endif
