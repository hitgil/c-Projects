#include "../inc/commonHeader.h"

int main()
{
    Bank myBank;
    int choice;
    std::cout << "\n*********************************\n";
    std::cout << "     Welcome to IccI Bank        \n";
    std::cout << "*********************************\n";

    while (true)
    {
        std::cout << "Are you an:\n"
                  << "1. Admin\n"
                  << "2. User\n"
                  << "3. Exit\n";
        std::cin >> choice;

        if (choice == 1)
        {
            handleAdminActions(myBank);
        }
        else if (choice == 2)
        {
            handleUserActions(myBank);
        }
        else if (choice == 3)
        {
            std::cout << "Exiting program. Thank you!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
