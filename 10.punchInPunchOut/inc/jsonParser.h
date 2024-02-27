#ifndef JSONPARSING_H
#define JSONPARSING_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <jsoncpp/json/json.h>
#include "./IPraser.h"

class JsonParser :public IParser {
public:
    void parse(const std::string& filename)override;

private:
    Json::Value parseJsonFromFile(const std::string& filename);
    void displayEmployeeDetailsFromJson(const Json::Value& root);
};

#endif