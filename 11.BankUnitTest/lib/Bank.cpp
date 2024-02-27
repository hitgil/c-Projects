#include "../inc/Bank.h"
#include "../inc/User.h"

bool Bank::addUserToBankDB(int accountId, std::string &name)
{
    bool success = true; 

    for (const auto &account : userAccounts)
    {
        if (account.accountId == accountId && account.name == name)
        {
            // std::cout << "Account already exists\n";
            success = false;
            break;
        }
    }

    if (success) 
    {
        Account userAccount;
        userAccount.name = name;
        userAccount.accountId = accountId;
        userAccount.balance = 0.0;
        userAccount.isActive = true;
        userAccounts.push_back(userAccount);
        // std::cout << "Account created successfully\n";
    }
    
    return success;
}


bool Bank::deleteUserFromBankDB(int accountId, std::string &name)
{
    bool success = false;

    for (auto it = userAccounts.begin(); it != userAccounts.end(); ++it)
    {
        if (it->accountId == accountId && it->name == name)
        {
            it = userAccounts.erase(it);
            std::cout << "Account deleted successfully\n";
            success = true;
            break;
        }
    }

    if (!success)
    {
        std::cout << "Account not found\n";
    }
    return success;
}

bool Bank::depositToUserAccount(IUser &user,int amount)
{
    std::string username = "sneha";
    
    
    int accountId = user.getUserId();
    
    std::string name = user.getUserName();
    double deposit = user.depositAmount(amount);
    bool success = false;

    for (auto &account : userAccounts)
    {
        if (account.accountId == accountId && account.name == name)
        {
            account.balance += deposit;
            std::cout << "Deposit of " << deposit << " Rs is successful\n";
            success = true;
            break;
        }
    }

    if (!success)
    {
        std::cout << "Invalid User\n";
    }
    return success;
}

bool Bank::withdrawFromUserAccount(IUser &user,int amount)
{
    int accountId = user.getUserId();
    std::string name = user.getUserName();
    double withdrawAmount = user.withdrawAmount(amount);
    bool success = false;

    for (auto &account : userAccounts)
    {
        if (account.accountId == accountId && account.name == name)
        {
            if (account.balance >= withdrawAmount)
            {
                account.balance -= withdrawAmount;
                std::cout << "Withdraw of " << withdrawAmount << " Rs is successful\n";
                success = true;
            }
            else
            {
                std::cout << "Insufficient balance\n";
            }
            break;
        }
    }

    if (!success)
    {
        std::cout << "Invalid User\n";
    }
    return success;
}

double Bank::getBalanceFromUserAccount(IUser &user)
{
    int accountId = user.getUserId();
    std::string name = user.getUserName();
    double balance = 0.0;

    for (const auto &account : userAccounts)
    {
        if (account.accountId == accountId && account.name == name)
        {
            balance = account.balance;
            break;
        }
    }

    if (balance == 0.0)
    {
        std::cout << "Invalid User\n";
    }
    return balance;
}

void Bank::PrintBalanceFromUserAccount(IUser &user)
{
    double balance = getBalanceFromUserAccount(user);
    std::cout << "Your account balance is: " << balance << "\n";
}

void Bank::displayAllUserDetails()
{
    std::cout << "User Details:\n";
    for (const auto &account : userAccounts)
    {
        std::cout << "Account ID: " << account.accountId << "\n";
        std::cout << "Name: " << account.name << "\n";
        std::cout << "Balance: " << account.balance << "\n";
        std::cout << "Active Status: " << (account.isActive ? "Active" : "Inactive") << "\n\n";
    }
}

bool Bank::validUser(int accountId, std::string &name)
{
    bool success = false;

    for (const auto &account : userAccounts)
    {
        if (account.accountId == accountId && account.name == name)
        {

            success = true;
            break;
        }
    }
    return success;
}