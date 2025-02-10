#include<iostream>
using namespace std;
class Car{
    int carId;
    string model;
    int year;
    bool isRented; 

    public:
    Car(){
        isRented = false;
    }
    Car(int carId, string model, int year, bool isRented){
        this->carId = carId;
        this->model = model;
        this->year = year;
        this->isRented = isRented;
    }
    void rentCar(){
        isRented = true;
        cout<<"\nCar Rented Successfully";
    }
    void returnCar(){
        isRented = false;
        cout<<"\nCar Returned Successfully";
    }
    bool isVintage(){
        return (year<2000)?true:false;
    }
};

int main(){
Car car1(23,"model1",1990, true);
car1.rentCar();

Car  car2(23,"model2",2020,true);
car2.rentCar();
car2.returnCar();    

return 0;
}