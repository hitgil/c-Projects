#ifndef READ_H
#define READ_H
#include <iostream>
#include <fstream>
#include <string>
#include "./jsonParser.h"
#include "./csvParser.h"
#include "./xmlParser.h"
#include "./employeeData.h"
#include "./IPraser.h"

#define JSON_FILE_NAME "employeeData.json"
#define CSV_FILE_NAME "employeeData.csv"
#define XML_FILE_NAME "employeeData.xml"

enum choice
{
    JSON_CHOICE = 1,
    CSV_CHOICE,
    XML_CHOICE
};

void writeDataIntoFile(const std::string &userInput, std::string fileName);
int getUserChoice();
void createEmployeeDataFile(const std::vector<employeeData> &employees);
IParser *selectParserBasedOnChoice(int choice);
void parseEmployeeData(int choice);

#endif
