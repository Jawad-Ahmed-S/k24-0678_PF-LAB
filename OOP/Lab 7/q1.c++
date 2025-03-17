#include<iostream>
using namespace std;
class Account{
    protected:
    string accountNumber;
    int balance;
    string AccountHolderName;
    string accountType;

    public:
    Account(string accountNumber,int balance,string AccountHolderName,string accountType){
        this->accountNumber=accountNumber;
        this->AccountHolderName = AccountHolderName;
        this->accountType = accountType;
        this->balance = balance;
    }
    void deposit(int amount){
            if(amount>0){
                balance+=amount;
            }
            else{
                cout<<"invalid amount";
            }
    }
    void withdraw(int amount){
        if(balance >= amount){
            balance-=amount;
        }
        else{
            cout<<"Insuffiecient Balance";
        }
    }
    void CalInterest(){

    }

    void PrintStatement(){
        
    }
    void getAccountInfo(){
        
        cout<<"Acount Number : "<<accountNumber<<endl;
        cout<<"Balance : "<<balance;
        cout<<"Holder Name : "<<AccountHolderName<<endl;
        cout<<"Type : "<<accountType<<endl;
    }

};
    class SavingAccount: public Account{
        float interestRate;
        int minBalance;
        public:
        SavingAccount(float rate,int balance, string accNum,string name,string type,int Balance): interestRate(rate),minBalance(balance),Account(accNum,Balance,name,"Saving") {}
        float CalInterest(){
            return (interestRate*balance);
        }

    };
    class FixedDepositAccount : public Account{
        float maturityDate;
        int fixedInterestRate;
        public:
        FixedDepositAccount(float maturity,int fixedRate, string accNum,string name,string type,int Balance): maturityDate(maturity),fixedInterestRate(fixedRate),Account(accNum,Balance,name,"Fixed Deposit") {

        }

        float CalInterest(){
            return (fixedInterestRate*balance);
        }    
    };
class CheckingAccount : public Account{

    public:
    CheckingAccount(string accNum,string name,string type,int Balance): Account(accNum,Balance,name,"Checking") {}

      
};
