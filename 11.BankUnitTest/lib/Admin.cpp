#include "../inc/Admin.h"

Admin::Admin(std::string adminName, int adminId) : Person(adminName), adminId(adminId)
{
}

int Admin::getAdminId()
{
    return adminId;
}

std::string Admin::getAdminName()
{
    return getName();
}

bool Admin::createUser(Bank &bank,std::string userName,int userId)
{
    // std::cout << "Creating a user account.\n";

    // std::string userName;
    // int userId;
    // std::cout << "Enter user name: ";
    // getline(std::cin, userName);

    // std::cout << "Enter user ID: ";
    // std::cin >> userId;
    // std::cin.ignore(245, '\n');

    return bank.addUserToBankDB(userId, userName);
}

bool Admin::deleteUser(Bank &bank,std::string userName,int userId)
{
    // std::cout << "Deleting a user account.\n";

    // std::string userName;
    // int userId;
    // std::cout << "Enter user name: ";
    // getline(std::cin, userName);

    // std::cout << "Enter user ID: ";
    // std::cin >> userId;
    // std::cin.ignore(245, '\n');

    return bank.deleteUserFromBankDB(userId, userName);
}
