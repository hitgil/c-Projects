#include "../inc/readData.h"
#include "../inc/exception.h"

void writeDataIntoFile(const std::string &userInput, std::string fileName)
{

    std::ifstream outfile;
    outfile.open(fileName);
}

int getUserChoice()
{
    std::string input;
    int choice;

    while (true)
    {
        std::cout << "Select a parser\n"
                  << JSON_CHOICE << ". JSON Parser\n"
                  << CSV_CHOICE << ". CSV Parser\n"
                  << XML_CHOICE << ". XML Parser\n";
        std::getline(std::cin, input);

        try
        {
            choice = std::stoi(input);
            if (choice >= JSON_CHOICE && choice <= XML_CHOICE)
            {
                return choice;
            }
            else
            {
                throw std::out_of_range("Number out of range.");
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid choice: "
                      << "You entered " << input << ". Please choose " << JSON_CHOICE << ", " << CSV_CHOICE << ", or " << XML_CHOICE << ".\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Please choose " << JSON_CHOICE << ", " << CSV_CHOICE << ", or " << XML_CHOICE << ".\n";
            continue;
        }
    }
}

void createEmployeeDataFile(const std::vector<employeeData> &employees)
{
    try
    {
        std::string userInput;

        userInput = convertToJSON(employees);
        writeDataIntoFile(userInput, JSON_FILE_NAME);

        userInput = convertToCSV(employees);
        writeDataIntoFile(userInput, CSV_FILE_NAME);

        userInput = convertToXML(employees);
        writeDataIntoFile(userInput, XML_FILE_NAME);
    }
    catch (const FileException &e)
    {
        std::cerr << "An error occurred while writing employee data: " << e.what() << '\n';
    }
}

void parseEmployeeData(int choice)
{
    IParser *selectedParser = nullptr;
    std::string fileName;

    switch (choice)
    {
    case JSON_CHOICE:
        fileName = JSON_FILE_NAME;
        break;
    case CSV_CHOICE:
        fileName = CSV_FILE_NAME;
        break;
    case XML_CHOICE:
        fileName = XML_FILE_NAME;
        break;
    default:
        std::cout << "Invalid choice";
        return;
    }

    selectedParser = selectParserBasedOnChoice(choice);
    if (selectedParser != nullptr)
    {
        selectedParser->parse(fileName);
        delete selectedParser;
    }
    else
    {
        std::cerr << "Error: Parser not initialized.";
    }
}

IParser *selectParserBasedOnChoice(int choice)
{
    IParser *parser = nullptr;

    switch (choice)
    {
    case JSON_CHOICE:
        std::cout << "Json Parser:";
        parser = new JsonParser;
        break;
    case CSV_CHOICE:
        std::cout << "CSV Parser:";
        parser = new CsvParser;
        break;
    case XML_CHOICE:
        std::cout << "XML Parser:";
        parser = new XmlParser;
        break;
    default:
        parser = nullptr;
    }
    return parser;
}
