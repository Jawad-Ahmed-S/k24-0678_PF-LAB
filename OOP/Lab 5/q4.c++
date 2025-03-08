#include<iostream>
using namespace std;
class BankAccount{
    int accountNumber;
    string accountHolderName;
    int balance;
    public:
       
    BankAccount(int accountNumber, string accountHolderName,int balance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;    
        cout << "Constructor called for " << accountHolderName << endl;
    }
    void Deposit(double amount){
        if(amount<=0){
            cout<<"Invalid deposit amount. Please enter a positive value."<<endl;
            return;
        }
        else{
            this->balance += amount;
            cout<<"Deposit Sucessful";
        }
    }
    void Withdraw(double amount){
        if(amount<=0){
            cout<<"Invalid withdrawal amount. Please enter a positive value."<<endl;
            return;
        }
        else{
            if(this->balance <=amount ){
                cout<<"Insufficient balance."<<endl;
                return;
            }
            else{
                this->balance -= amount;
                cout<<"Withdrawal Sucessful\n";
            }
        }
    }
    void DisplayDetails(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder Name: "<<accountHolderName<<endl;
        cout<<"Current Balance: "<<balance<<endl;
    }
};
int main() {
    BankAccount account[3] = {
        {465798, "Jawad", 1000},
        {5642, "Alice", 2000},
        {5643, "Bob", 3000}};
        
    for(int i=0; i<3; i++){
        cout<<"\n";
        account[i].DisplayDetails();
        cout<<"\n";
        account[i].Deposit(500);
        cout<<"\n";
        account[i].DisplayDetails();        
        account[i].Withdraw(200);
        cout<<"\n";
        account[i].DisplayDetails();        
    }
    return 0;
}