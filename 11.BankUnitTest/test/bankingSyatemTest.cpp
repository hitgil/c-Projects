#include <gmock/gmock.h>
#include "../inc/Bank.h"
#include "../inc/Admin.h"
#include "../inc/User.h"

class MockBank : public Bank
{
public:
    MOCK_METHOD(bool, addUserToBankDB, (int accountId, std::string &name));
    MOCK_METHOD(bool, deleteUserFromBankDB, (int accountId, std::string &name));
};

class MockUser : public IUser
{
    std::string username;
    int userId;

public:
    MockUser(std::string username, int userId) : username(username), userId(userId){};
    MOCK_METHOD(int, getUserId, ());
    MOCK_METHOD(std::string, getUserName, (), (override));
    MOCK_METHOD(double, depositAmount, (int), (override));
    MOCK_METHOD(double, withdrawAmount, (int), (override));
};

class ParamtestForBank : public ::testing::TestWithParam<std::tuple<std::string, int, double, double>>
{

protected:
    Bank bank;
};

INSTANTIATE_TEST_SUITE_P(, ParamtestForBank,
                         ::testing::Values(
                             std::make_tuple("UserOne", 1001, 10000.0, 100.0),
                             std::make_tuple("UserOne", 1001, 20000.0, 10089.0),
                             std::make_tuple("UserOne", 1001, 30000.0, 1234.0),
                             std::make_tuple("UserOne", 1001, 40000.0, 8765.0)));

TEST_P(ParamtestForBank, DepositToUserAccountSuccess)
{

    // User user("UserOne", 1001);
    MockUser mockuser("UserOne", 1001);
    Bank bank;
    Admin admin("admin One", 1001);
    int accountId = std::get<1>(GetParam());
    std::string userName = std::get<0>(GetParam());
    double depositAmount = std::get<2>(GetParam());
    admin.createUser(bank, userName, accountId);

    EXPECT_CALL(mockuser, getUserId())
        .WillRepeatedly(::testing::Return(accountId));
    EXPECT_CALL(mockuser, getUserName())
        .WillRepeatedly(::testing::Return(userName));
    EXPECT_CALL(mockuser, depositAmount(depositAmount))
        .WillRepeatedly(::testing::Return(depositAmount));

    bool result = bank.depositToUserAccount(mockuser, depositAmount);

    ASSERT_TRUE(result);
}

// TEST_P(ParamtestForBank, WithdrawFromUserAccountSuccess)
// {
//     MockUser user("UserOne", 1001);
//     Bank bank;
//     Admin admin("admin One", 1001);
//     int accountId = std::get<1>(GetParam());
//     std::string userName = std::get<0>(GetParam());
//     double withdrawamount = std::get<3>(GetParam());
//     double depositAmount = std::get<2>(GetParam());
//     admin.createUser(bank, userName, accountId);
//     User oldUser("UserOne", 1001);
//     bank.depositToUserAccount(oldUser, depositAmount);

//     EXPECT_CALL(user, getUserId())
//         .WillRepeatedly(::testing::Return(accountId));
//     EXPECT_CALL(user, getUserName())
//         .WillRepeatedly(::testing::Return(userName));
//     EXPECT_CALL(user, withdrawAmount(withdrawamount))
//         .WillRepeatedly(::testing::Return(withdrawamount));

//     bool result = bank.withdrawFromUserAccount(user, withdrawamount);

//     ASSERT_TRUE(result);
// }

// TEST_P(ParamtestForBank, GetBalanceFromUserAccountSuccess)
// {
//     MockUser user("UserOne", 1001);
//     Bank bank;
//     Admin admin("admin One", 1001);
//     User oldUser("UserOne", 1001);

//     int accountId = std::get<1>(GetParam());
//     std::string userName = std::get<0>(GetParam());
//     double depositAmount = std::get<2>(GetParam());

//     admin.createUser(bank, userName, accountId); // create OldUser
//     bank.depositToUserAccount(oldUser, depositAmount);
//     double initialBalance = bank.getBalanceFromUserAccount(oldUser);

//     EXPECT_CALL(user, getUserId())
//         .WillRepeatedly(::testing::Return(accountId));
//     EXPECT_CALL(user, getUserName())
//         .WillRepeatedly(::testing::Return(userName));

//     double balance = bank.getBalanceFromUserAccount(user);
//     EXPECT_EQ(initialBalance, balance);
// }

// // TEST(BankTest, isValidUser)
// // {
// //     Bank bank;
// //     Admin admin("AdminOne", 1);
// //     User user("UserOne", 1001);
// //     std::string userName = user.getName();
// //     int userId = user.getUserId();
// //     admin.createUser(bank, userName, userId); // adding user to dataBase

// //     bool isValid = bank.validUser(userId, userName);
// //     EXPECT_TRUE(isValid);
// // }

TEST_P(ParamtestForBank, CreateUserSuccess)
{
    // Arrange
    MockBank bank;
    Admin admin("Admin One", 1001);
    int userId = std::get<1>(GetParam());
    std::string userName = std::get<0>(GetParam());

    // Expectations
    EXPECT_CALL(bank, addUserToBankDB(userId, userName))
        .WillOnce(::testing::Return(true));

    // Act
    bool result = admin.createUser(bank, userName, userId);

    // Assert
    ASSERT_TRUE(result);
}

// TEST_P(ParamtestForBank, CreateUserFailure)
// {
//     // Arrange
//     MockBank bank;
//     Admin admin("Admin One", 1001);
//     int userId = std::get<1>(GetParam());
//     std::string userName = std::get<0>(GetParam());
//     admin.createUser(bank, userName, userId);

//     // call to addUserToBankDB fails
//     EXPECT_CALL(bank, addUserToBankDB(userId, userName))
//         .WillOnce(::testing::Return(false));

//     // Act
//     bool resultOne = admin.createUser(bank, userName, userId);

//     // Assert
//     ASSERT_FALSE(resultOne);
// }

// TEST_P(ParamtestForBank, DeleteUserSuccess)
// {
//     MockBank bank;
//     Admin admin("Admin One", 1001);
//     int userId = std::get<1>(GetParam());
//     std::string userName = std::get<0>(GetParam());
//     admin.createUser(bank, userName, userId);

//     EXPECT_CALL(bank, deleteUserFromBankDB(userId, userName))
//         .WillOnce(::testing::Return(true));

//     bool result = admin.deleteUser(bank,userName,userId);

//     ASSERT_TRUE(result);
// }

// TEST_P(ParamtestForBank, DeleteUser_Failure)
// {
//     MockBank bank;
//     Admin admin("Admin One", 1001);
//     int userId = std::get<1>(GetParam());
//     std::string userName = std::get<0>(GetParam());

//     EXPECT_CALL(bank, deleteUserFromBankDB(userId, userName))
//         .WillOnce(::testing::Return(false));

//     bool result = admin.deleteUser(bank,userName,userId);

//     ASSERT_FALSE(result);
// }

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}