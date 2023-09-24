#include <iostream>
#include "bank.h"

int main()
{
    Bank bank;

    Account *account1 = bank.createAccount(1001, 1234);
    Account *account2 = bank.createAccount(1002, 5678);

    int choice;
    int accNumber;
    int pin;
    double amount;

    while (true)
    {
        std::cout << "Welcome to the Console Banking System" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Enter Account Number: ";
            std::cin >> accNumber;
            std::cout << "Enter PIN: ";
            std::cin >> pin;

            Account *account = bank.findAccount(accNumber);

            if (account != nullptr && account->checkPin(pin))
            {
                while (true)
                {
                    std::cout << "1. Deposit" << std::endl;
                    std::cout << "2. Withdraw" << std::endl;
                    std::cout << "3. Check Balance" << std::endl;
                    std::cout << "4. Logout" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        std::cout << "Enter amount to deposit: ";
                        std::cin >> amount;
                        account->deposit(amount);
                        break;
                    case 2:
                        std::cout << "Enter amount to withdraw: ";
                        std::cin >> amount;
                        account->withdraw(amount);
                        break;
                    case 3:
                        std::cout << "Your balance: $" << account->getBalance() << std::endl;
                        break;
                    case 4:
                        account->checkAccountStatus();
                        break;
                    default:
                        std::cout << "Invalid choice. Try again." << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Invalid account number or PIN. Try again." << std::endl;
            }
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
