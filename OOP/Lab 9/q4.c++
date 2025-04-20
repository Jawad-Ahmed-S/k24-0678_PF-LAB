#include<iostream>
using namespace std;
class PayementMethod{
protected:
virtual void processPayement(double amount)=0;
    };
class CreditCard : public PayementMethod{
    string cardNumber;
    public:
    CreditCard(string num):cardNumber(num){};

    void processPayement(double amount) override{
        cout<<"Processing credit card payment of $"<<amount<<endl;
    }

};
class DigitalWallet: public PayementMethod{
 int balance;
 public:
 DigitalWallet(int bal):balance(bal){};
    void processPayement(double amount)  override{
        if(balance >= amount){

        cout<<"Processing digital wallet payment of $"<<amount<<endl;
        balance -= amount;
        }
        else{
            cout<<"Insufficient balance in digital wallet"<<endl;
        }
    }
};
int main() {
    DigitalWallet dw(4560);
    CreditCard cc("1234567890");
    dw.processPayement(500);
    cc.processPayement(500);
 
    return 0;
}