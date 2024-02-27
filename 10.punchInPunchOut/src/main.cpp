#include "../inc/readData.h"
#include "../inc/employeeData.h"

int main()
{
    std::vector<employeeData> employee = createEmployeeList();
    int userChoice = getUserChoice();
    createEmployeeDataFile (employee);
    parseEmployeeData(userChoice);

    return 0;
}
