#include "../inc/JsonParsing.h"
#include "../inc/CSVParsing.h"
#include "../inc/XmlParsing.h"


int main()
{
    JsonParsing parser;
    CsvParsing csvparser;
    XmlParsing xmlparser;
    int choice;
    std::string filePath;

    std::cout << "Choose"
              << "\n1. JSON Parser"
              << "\n2. CSV Parser"
              << "\n3. XML Parser";
    std::cin >> choice;

    std::cout << "Enter file path: ";
    std::cin >> filePath;

    switch (choice)
    {
    case 1:
        parser.parse(filePath);
        break;
    case 2:
        csvparser.parse(filePath);
        break;
    case 3:
        xmlparser.parse(filePath);
        break;
    default:
        std::cout << "Invalid choice. Please choose 1, 2, or 3." << std::endl;
        break;
    }

    return 0;
}
