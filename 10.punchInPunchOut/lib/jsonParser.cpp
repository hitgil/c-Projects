#include "../inc/jsonParser.h"
#include "../inc/exception.h"

void JsonParser::parse(const std::string &filename)
{
    try
    {
        Json::Value root = parseJsonFromFile(filename);
        displayEmployeeDetailsFromJson(root);
    }
    catch (const FileException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const JsonParseException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error " << e.what() << std::endl;
    }
}

Json::Value JsonParser::parseJsonFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    Json::Reader reader;
    Json::Value root;

    if (!file.is_open())
    {
        throw FileException("Unable to open the file: " + filename);
    }

    if (!reader.parse(file, root))
    {
        throw JsonParseException("Failed to parse JSON from " + filename + ". Error: " + reader.getFormattedErrorMessages());
    }
    return root;
}

void JsonParser::displayEmployeeDetailsFromJson(const Json::Value &root)
{
    std::cout << "\nJSON data has been successfully parsed.\n\n";

    for (const Json::Value &employee : root)
    {
        if (!employee.isObject())
        {
            throw std::runtime_error("JSON file is empty");
        }

        if (employee.isMember("ID"))
        {
            std::cout << "Employee ID: " << employee["ID"].asString() << std::endl;
        }
        if (employee.isMember("employeeName"))
        {
            std::cout << "Employee name: " << employee["employeeName"].asString() << std::endl;
        }
        if (employee.isMember("punchIN"))
        {
            std::cout << employee["employeeName"].asString() << " punchIn at " << employee["punchIN"].asString() << std::endl;
        }

        std::cout << "************************************************************************\n";
    }
}
