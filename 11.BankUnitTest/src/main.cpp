#include "../inc/Bank.h"
#include "../inc/Admin.h"
#include "../inc/User.h"

void adminActions(Bank &bank, Admin &admin)
{
    std::cout << "\n************************************\n"
              << " Welcome Admin " << admin.getName() << "\n"
              << "************************************\n"
              << "1. Create user\n"
              << "2. Delete user\n"
              << "3. User List\n"
              << "3. Go back\n";
    int choice = 0;
    std::cin >> choice;
    std::cin.ignore(245, '\n');

    switch (choice)
    {
    case 1:
    {
        admin.createUser(bank);
        break;
    }
    case 2:
    {
        admin.deleteUser(bank);
        break;
    }
    case 3:
    {
        bank.displayAllUserDetails();
        break;
    }
    default:
        break;
    }
}
void UserActions(Bank &bank, User &user)
{
    std::cout << "\n************************************\n"
              << "Welcome user " << user.getName() << "\n"
              << "************************************\n"
              << "1. Deposit\n"
              << "2. Withdraw\n"
              << "3. Balance\n"
              << "4. Go back\n";
    int choice = 0;
    std::cin >> choice;
    std::cin.ignore(256, '\n');

    switch (choice)
    {
    case 1:
    {
        bank.depositToUserAccount(user);
        break;
    }
    case 2:
    {
        bank.withdrawFromUserAccount(user);
        break;
    }
    case 3:
    {
        bank.PrintBalanceFromUserAccount(user);
        break;
    }
    default:
        break;
    }
}

void logInUser(Bank &bank)
{
    std::cout << "******************\n"
              << "       LogIN      \n"
              << "******************\n";
    std::string userName;
    int userId;
    std::cout << "Enter the user name\n";
    getline(std::cin, userName);
    std::cout << "Enter the user Id\n";
    std::cin >> userId;
    std::cin.ignore(245, '\n');

    if (bank.validUser(userId, userName))
    {
        std::cout << "Login Successfull\n";
        User user(userName, userId);
        UserActions(bank, user);
    }
    else
    {
        std::cout << "Ivalid User\n";
    }
}
int main()
{

    Bank bank;
    Admin admin("AdminSneha", 1);
    adminActions(bank, admin);
    logInUser(bank);

    return 0;
}