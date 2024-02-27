#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

typedef struct
{
    std::string employeeName;
    int ID;
    std::time_t punchIN;
} employeeData;

std::vector<employeeData> createEmployeeList();
employeeData addSingleEmployee();
std::string convertToJSON(const std::vector<employeeData> &employees);
std::string convertToCSV(const std::vector<employeeData> &employees);
std::string convertToXML(const std::vector<employeeData> &employees);

#endif
