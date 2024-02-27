#ifndef CSVPARSING_H
#define CSVPARSING_H
#include <fstream>
#include <stdexcept>
#include "rapidcsv.h"
#include "./IPraser.h"


class CsvParser :public IParser
{
public:
    void parse(const std::string& filename)override;
};

#endif