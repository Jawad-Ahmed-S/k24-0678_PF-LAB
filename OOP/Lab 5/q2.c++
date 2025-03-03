#include<iostream>
using namespace std;
 float validate(const float Interest){
        if(Interest>0.0 && Interest<0.5){
            return Interest;
        }    
        cout<<"Invalid";
        return 0.0;
 }
class LoanHelper{
    const float InterestRate;
    float amountLoan;
    float AmountToBePaid;
    int monthsToBePaidIn; 
    public:
    LoanHelper(const float InterestRate,int monthsToBePaidIn,float amountLoan):InterestRate(validate(InterestRate)),monthsToBePaidIn(monthsToBePaidIn),amountLoan(amountLoan){ }
    void LoanCalculator(){
        AmountToBePaid = (amountLoan/monthsToBePaidIn);
        AmountToBePaid += (amountLoan * InterestRate);
        cout<<"Amount to be paid Monthly: "<<AmountToBePaid;
    }
     
 };
int main(){
    int months;
    float interestRate;
    cout<<"Enter the interest rate : ";
    cin>>interestRate;
    cout<<"Enter the number of months : ";
    cin>>months;
    float amount;
    cout<<"Enter the amount loaned : ";
    cin>>amount;
    LoanHelper l1(interestRate,months,amount);
    l1.LoanCalculator();
}