#include "../inc/CSVParsing.h"
#include <sstream>

void CsvParsing::parse(const std::string &filename)
{
    try
    {
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1));
        std::cout << "\nCSV data from '" << filename << "' has been successfully parsed.\n"
                  << std::endl;

        for (int rowIdx = 0; rowIdx < doc.GetRowCount(); ++rowIdx)
        {
            std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);
            std::cout << "Restaurant Details:" << std::endl;
            std::cout << "  Name: " << row[0] << std::endl;
            std::cout << "  Location: " << row[1] << std::endl;
            std::cout << "  Cuisine: " << row[2] << std::endl;
            std::cout << "  Ratings:" << std::endl;
            std::cout << "    Google: " << row[3] << std::endl;
            std::cout << "    Swiggy: " << row[4] << std::endl;
            std::cout << "    Zomato: " << row[5] << std::endl;
            std::cout << "  Contact Information:" << std::endl;
            std::cout << "    Phone: " << row[6] << std::endl;
            std::cout << "    Email: " << row[7] << std::endl;
            std::cout << "    Website: " << row[8] << std::endl;
            std::cout << "  Popular Dishes: " << row[9] << std::endl;
            std::cout << "  Vegetarian Friendly: " << (row[10] == "true" ? "Yes" : "No") << std::endl;
            std::cout << "  Outdoor Seating: " << (row[11] == "true" ? "Yes" : "No") << std::endl;
            std::cout << std::endl;
            std::cout << "-----------------------------------\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to parse CSV file: " << e.what() << std::endl;
    }
}
