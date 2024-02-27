#include "../inc/csvParser.h"
#include"../inc/exception.h"



void CsvParser::parse(const std::string &filename)
{
    try
    {
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1));

        if (doc.GetRowCount() == 0)
        {
            throw EmptyCSVException("CSV file is empty");
        }

        std::cout << "\nCSV data from '" << filename << "' has been successfully parsed.\n"
                  << std::endl;

        for (int rowIdx = 0; rowIdx < doc.GetRowCount(); ++rowIdx)
        {
            std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);
            if (row.size() < 3)
            {
                throw InsufficientDataException("Insufficient data in row " + std::to_string(rowIdx));
            }

            std::cout << "  Employee ID: " << row[1] << std::endl;
            std::cout << "  Employee Name: " << row[0] << std::endl;
            std::cout << "  " << row[0] << "  punched IN at " << row[2] << std::endl;
            std::cout << std::endl;
            std::cout << "-----------------------------------\n";
        }
    }
    catch (const EmptyCSVException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const InsufficientDataException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
