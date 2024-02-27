#include"../inc/commonHeader.h"

void handleAdminActions(Bank &myBank)
{
    std::string adminName;
    std::cout << "Enter Admin Name: ";
    std::cin >> adminName;

    Admin bankAdmin(adminName, myBank);
    std::cout << "Welcome, Admin " << bankAdmin.getName() << "." << std::endl;

    int adminChoice;
    std::cout << "Enter your choice:\n"
              << "1. Create User\n"
              << "2. Delete User\n"
              << "3. Back to Main Menu\n";
    std::cin >> adminChoice;

    if (adminChoice == 1)
    {
        int userId;
        std::string userName;
        std::cout << "Enter User ID to create: ";
        std::cin >> userId;
        std::cout << "Enter User Name: ";
        std::cin >> userName;
        bankAdmin.createUser(userId, userName);
        std::cout << "User " << userName << " created." << std::endl;
    }
    else if (adminChoice == 2)
    {
        int userId;
        std::cout << "Enter User ID to delete: ";
        std::cin >> userId;
        bankAdmin.deleteUser(userId);
        std::cout << "User deleted." << std::endl;
    }
    else if (adminChoice == 3)
    {
        return;
    }
}

void handleUserActions(Bank &myBank)
{
    int userId;
    std::string userName;
    std::cout << "Enter your User ID: ";
    std::cin >> userId;
    std::cout << "Enter your Name: ";
    std::cin >> userName;
    if (myBank.doesUserExist(userId))
    {
        User bankUser(userName, myBank, userId);

        std::cout << "Welcome, " << bankUser.getName() << "." << std::endl;

        int userChoice;
        std::cout << "Enter your choice:\n"
                  << "1. Deposit\n"
                  << "2. Withdraw\n"
                  << "3. Check Balance\n"
                  << "4. Back to Main Menu\n";
        std::cin >> userChoice;

        if (userChoice == 1)
        {
            double amount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            bankUser.deposit(amount);
            std::cout << "Deposited $" << amount << std::endl;
        }
        else if (userChoice == 2)
        {
            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            bankUser.withdraw(amount);
            std::cout << "Withdrew $" << amount << std::endl;
        }
        else if (userChoice == 3)
        {
            std::cout << "Your balance: $" << bankUser.checkBalance() << std::endl;
        }
        else if (userChoice == 4)
        {
            return;
        }
    }
    else
    {
        std::cerr << "Error: Account not found.\n";
    }
}
