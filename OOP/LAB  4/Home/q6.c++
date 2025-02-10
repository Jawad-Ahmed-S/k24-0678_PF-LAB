#include<iostream>
using namespace std;
class Account{
    string AccountNumber;
    string AccountHolderName;
    double Balance;
    public:
    Account(){
        Balance = 0.0;
    }
    Account(string accountNumber, string accountHolderName, double initialBalance){
        this->AccountNumber = accountNumber;
        this->AccountHolderName = accountHolderName;
        this->Balance = initialBalance;
    }
    void deposit(double amount){
         if(amount<0){
            cout<<"\nInvalid amount!"<<endl;
            return;
        }
        else{
        this->Balance += amount;
        }
    }
    void WithDraw(double amount){
        if(amount>Balance){
            cout<<"\nInsufficient Balance!"<<endl;
            return;
        }
        else{
        this->Balance -= amount;
        }
    }
    void DisplayDetails(){
        cout<<"\n\nAccount Holder Name : "<<this->AccountHolderName<<endl;
        cout<<"Account Number : "<<this->AccountNumber<<endl;
        cout<<"Current Balance : "<<this->Balance<<endl;
    }
};
int main(){

Account A1("456","Jawad",554364.054),A2("453","Ibrahim",22054.3),A3("978","Ahmed",645.65456);
A1.DisplayDetails();
A1.WithDraw(3243.34);
A1.DisplayDetails();

A2.DisplayDetails();
A2.WithDraw(342.324);
A2.DisplayDetails();

A3.DisplayDetails();
A3.deposit(2343.23);
A3.DisplayDetails();
return 0;
}