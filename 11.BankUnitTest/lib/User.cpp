#include "../inc/User.h"

// void User::enterUserDetails()
// {
//     std::cout << " User Details. \n";

//     std::string userName;
//     int userId;
//     std::cout << " Enter user name. \n";
//     getline(std::cin, userName);
//     setName(userName);

//     std::cout << " Enter user Id. \n";
//     std::cin >> userId;
//     std::cin.ignore(245, '\n');

//     this->userId = userId;
// }

int User::getUserId()
{
    return userId;
}

std::string User::getUserName()
{
    return getName();
}

double User::depositAmount(int amount)
{
    // double amount = 0.0;
    // std::cout << " Enter the amount to deposit.\n";
    // std::cin >> amount;
    // std::cin.ignore(245, '\n');

    return amount;
}

double User::withdrawAmount(int amount)
{
    // double amount = 0.0;
    // std::cout << " Enter the amount to withdraw.\n";
    // std::cin >> amount;
    // std::cin.ignore(245, '\n');

    return amount;
}
