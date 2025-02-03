#include<iostream>
#include<conio.h>
using namespace std;

class toolBooth{
public:
    unsigned int totalCars;
    double MoneyCollected;
    
public:
    toolBooth(){
        totalCars = 0;
        MoneyCollected = 0;
    }
    void payingCar(){
        totalCars++;
        MoneyCollected += 0.5;
    }
    void noPayCar(){
        totalCars++;
    }
    void Display(){
        cout << "\n Total Cars passed : " << totalCars << endl;
        cout << "Total Money Collected : " << MoneyCollected << endl;
    }
};

int main(){
    toolBooth T1;
    char input;

    cout << "Enter \np :Paying \nn : nonPaying" << endl;
    while(1){
        cout << "choice:";
        input = getche();

        switch(input){
            case 'p':
                T1.payingCar();
                break;
            case 'n':
                T1.noPayCar();
                break;
            case 27:
                T1.Display();
                break;
        }
    }
    return 0;
}
