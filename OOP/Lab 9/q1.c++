#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string modelName;
    double rate;
    public:
    Vehicle(string name,double rate){
        this->modelName = name;
        this->rate = rate;
    }
    virtual double getDailyRate()=0;
    virtual void displayDetails()=0;
};
class Car :public Vehicle{
    bool isAc;
    public:
    Car(string name,double rate,bool Ac):Vehicle(name,rate),isAc(Ac){};
    double getDailyRate()override{
        return rate;
    }
    void displayDetails(){
        cout<<"Car: "<<endl;
        cout<<"Model Name: "<<modelName<<endl;
        cout<<"Daily Rate: "<<rate<<endl;
        cout<<"AC: "<<isAc<<endl;
    }
};
class Bike :public Vehicle{
    public:
    Bike(string name,double rate):Vehicle(name,rate){};
    double getDailyRate()override{
        return rate;
    }
    void displayDetails(){
        cout<<"Bike: "<<endl;
        cout<<"Model Name: "<<modelName<<endl;
        cout<<"Daily Rate: "<<rate<<endl;
    }
    };
int main(){
    Vehicle **v = new Vehicle*[2];
    v[0] = new Car("Honda City", 5000, true);
    v[1] = new Bike("Honda Shine", 3000);
    for(int i=0;i<2;i++){
        cout<<v[i]->getDailyRate()<<endl;
        v[i]->displayDetails();
        cout<<endl;
    }
    return 0;
}
