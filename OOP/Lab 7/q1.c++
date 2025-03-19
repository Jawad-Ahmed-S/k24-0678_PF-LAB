#include <iostream>
using namespace std;
class Account
{
protected:
    string accountNumber;
    int balance;
    string AccountHolderName;
    string accountType;

public:
    Account(string accountNumber, int balance, string AccountHolderName, string accountType)
    {
        this->accountNumber = accountNumber;
        this->AccountHolderName = AccountHolderName;
        this->accountType = accountType;
        this->balance = balance;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "invalid amount";
        }
    }
    void withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insuffiecient Balance";
        }
    }
    virtual float CallInterest()
    {
        return 0.0;
    }

    virtual void PrintStatement()
    {
    }
    virtual void getAccountInfo()
    {

        cout << "Acount Number : " << accountNumber << endl;
        cout << "Balance : " << balance;
        cout << "Holder Name : " << AccountHolderName << endl;
        cout << "Type : " << accountType << endl;
    }
};
class SavingAccount : public Account
{
    float interestRate;
    int minBalance;

public:
    SavingAccount(float rate, int balance, string accNum, string name, int Balance) : Account(accNum, Balance, name, "Saving"), interestRate(rate), minBalance(balance) {}

    float CallInterest() override
    {
        return (interestRate * balance);
    }
};
class FixedDepositAccount : public Account
{
    float maturityDate;
    int fixedInterestRate;

public:
    FixedDepositAccount(float maturity, int fixedRate, string accNum, string name, int Balance) : Account(accNum, Balance, name, "Fixed Deposit"), maturityDate(maturity), fixedInterestRate(fixedRate)
    {
    }

    float CallInterest() override
    {
        return (fixedInterestRate * balance);
    }
};
class CheckingAccount : public Account
{

public:
    CheckingAccount(string accNum, string name, int Balance) : Account(accNum, Balance, name, "Checking") {}
};
int main()
{
    Account *acc[3];
    acc[0] = new SavingAccount(0.05, 1000, "SA001", "John Doe", 1000);
    acc[1] = new FixedDepositAccount(0.02, 2000, "FD001", "Jane Doe", 5000);
    acc[2] = new CheckingAccount("CH001", "Jane Doe", 2000);

    acc[0]->CallInterest();
    acc[1]->CallInterest();
    acc[2]->CallInterest();
    for (int i = 0; i < 3; i++)
    {
        acc[i]->PrintStatement();
        acc[i]->getAccountInfo();
        cout << "Interest: " << acc[i]->CallInterest() << endl;
        cout << "--------------------" << endl;
    }
}
