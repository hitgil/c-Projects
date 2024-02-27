#ifndef CSVPARSING_H
#define CSVPARSING_H
#include "IParsing.h"
#include "rapidcsv.h"

class CsvParsing : public IParsing
{
public:
    void parse(const std::string &filename) override;
};

#endif