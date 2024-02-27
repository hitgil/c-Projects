#include "../inc/xmlParser.h"
#include "../inc/exception.h"

void XmlParser::parse(const std::string &filename)
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile(filename.c_str());
    try
    {
        if (eResult != tinyxml2::XML_SUCCESS)
        {
            throw XmlParseException("Unable to open the XML file: " + filename);
        }

        tinyxml2::XMLElement *root = doc.FirstChildElement("employees");
        if (root == nullptr)
        {
            throw XmlElementNotFoundException("No 'employees' element found in XML file: " + filename);
        }

        std::cout << "\nXML data has been successfully parsed.\n\n";

        for (tinyxml2::XMLElement *employeeElement = root->FirstChildElement("employee");
             employeeElement != nullptr;
             employeeElement = employeeElement->NextSiblingElement("employee"))
        {
            try
            {
                displayEmployeeDetailsFromXML(employeeElement);
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "Error processing employee element: " << e.what() << std::endl;
                throw;
            }
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Failed to parse : " << e.what() << std::endl;
        throw;
    }
}

void XmlParser::displayEmployeeDetailsFromXML(const tinyxml2::XMLElement *employeeElement)
{
    if (employeeElement == nullptr)
    {
        throw XmlElementNotFoundException("No 'child elements of employees' found");
    }

    const char *employeeId = employeeElement->FirstChildElement("id")->GetText();
    const char *name = employeeElement->FirstChildElement("employeeName")->GetText();
    const char *punchInTime = employeeElement->FirstChildElement("punchInTime")->GetText();

    if (!employeeId || !name || !punchInTime)
    {
        throw std::runtime_error("Missing required employee information in XML element");
    }

    std::cout << "Employee ID: " << employeeId << std::endl;
    std::cout << "Employee Name: " << name << std::endl;
    std::cout << "Punch In Time: " << punchInTime << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
