
#include "../inc/employeeData.h"

employeeData addSingleEmployee()
{
    employeeData newEmployee;
    std::string input;

    std::cout << "Enter employee name: ";
    std::getline(std::cin, newEmployee.employeeName);

    while (true)
    {
        std::cout << "Enter employee ID: ";
        std::getline(std::cin, input);

        try
        {
            newEmployee.ID = std::stoi(input);
            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid input of " << input << ". Please enter a valid ID.\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "ID is out of range. Please enter a smaller number.\n";
        }
    }

    return newEmployee;
}

std::vector<employeeData> createEmployeeList()
{
    std::vector<employeeData> employees;
    char choice;

    do
    {
        employees.push_back(addSingleEmployee());

        std::cout << "Do you want to add another employee? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    return employees;
}

std::string convertToJSON(const std::vector<employeeData> &employees)
{
    std::string output = "[";
    bool firstElement = true;

    for (const auto &emp : employees)
    {
        if (!firstElement)
        {
            output += ", ";
        }
        firstElement = false;
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&emp.punchIN));
        output += "{";
        output += "\"employeeName\": \"" + emp.employeeName + "\", ";
        output += "\"ID\": " + std::to_string(emp.ID) + ", ";
        output += "\"punchIN\": \"" + std::string(buffer) + "\"";
        output += "}";
    }
    output += "]";
    return output;
}

std::string convertToCSV(const std::vector<employeeData> &employees)
{
    std::string output = "Employee Name,ID,Punch-In Time\n";

    for (const auto &emp : employees)
    {
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&emp.punchIN));

        output += "\"" + emp.employeeName + "\",";
        output += std::to_string(emp.ID) + ",";
        output += std::string(buffer) + "\n";
    }
    return output;
}

std::string convertToXML(const std::vector<employeeData> &employees)
{

    std::string output = "<employees>\n";

    for (const auto &emp : employees)
    {
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&emp.punchIN));

        std::string name = emp.employeeName;
        output += "  <employee>\n";
        output += "    <employeeName>" + name + "</employeeName>\n";
        output += "    <id>" + std::to_string(emp.ID) + "</id>\n";
        output += "    <punchInTime>" + std::string(buffer) + "</punchInTime>\n";
        output += "  </employee>\n";
    }

    output += "</employees>";
    return output;
}
