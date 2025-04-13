#include<iostream>
using namespace std;
class BankAccount{
    protected:
    string accNumber;
    int balance;
    float interestRate;
    public:
    BankAccount(){
        accNumber = "";
        balance = 0;
    }
    BankAccount(string accNumber, int balance,float interestRate){
        this->accNumber = accNumber;
        this->balance = balance;
        this->interestRate = interestRate;
    }

    int operator+(BankAccount &other)
    {
        return balance + other.balance;
    }
    int operator-(int amount)
    {
        return balance - amount;
    }
    int operator*()
    {
        return balance * interestRate;
    }
    int operator/(int months)
    {
        return balance / months;
    }
    virtual void calculateInterest(){
        cout<<"Interest rate: "<<interestRate;
        cout<<", Interest earned: "<<this<<endl;
    }
    void deposit(int amount){
        cout << "Depositing " << amount << endl;
        balance += amount;
    }
    void deposit(double CheckId,int amount){
        cout << "Check ID: " << CheckId << ", Depositing " << amount << endl;
        balance += amount;
    }
    void deposit(string IBAN,int amount){
        cout << "IBAN: " << IBAN << ", Depositing " << amount << endl;
        balance += amount;
    }
    virtual void withdraw(int amount){
        if(balance >= amount){
            cout << "Withdrawing " << amount << endl;
            balance -= amount;
        }
        else{
            cout << "Insufficient balance" << endl;
        }
    }
};
class SavingsAccount: public BankAccount{
    // int InterestRate;
    public:
    SavingsAccount(string accNumber,int initialBalance): BankAccount(accNumber,initialBalance,5){
        balance = initialBalance;
    }
    void calculateInterest(){
        balance += (balance * interestRate) / 100;
    }
    virtual void withdraw(int amount) override {
        if(balance<500){
            cout << "Current account balance should not be less than $500. Withdrawal cancelled." << endl;
            return;
        }
        else{

        if(balance >= amount ){
            
            cout << "Withdrawing " << amount << endl;
            balance -= amount;
        }
        else{
            cout << "Insufficient balance" << endl;
        }
        }
    }
};
class CurrentAccount: public BankAccount{
    // int InterestRate;
    public:
    CurrentAccount(string accNumber,int initialBalance): BankAccount(accNumber,initialBalance,0){
        balance = initialBalance;
    }
    void calculateInterest(){
        balance += (balance * interestRate) / 100;
    }
    virtual void withdraw(int amount) override {
        if(amount>1000){
            cout << "Withdrawal amount should not be more than $1000. Withdrawal cancelled." << endl;
            return;
        }
        else{
            if(balance >= amount ){
                cout << "Withdrawing " << amount << endl;
                balance -= amount;
            }
            else{
                cout << "Insufficient balance" << endl;
            }
        }
    }
};
int main() {

     SavingsAccount saving("456123",10000);
     CurrentAccount current("789456",2000);
     saving.deposit(5000);
     current.deposit(456,5000);
     saving.calculateInterest();
     current.withdraw(1000);
     saving.deposit("PKGSFG4567987",1000);
 
    return 0;
}