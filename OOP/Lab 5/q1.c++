#include<iostream>
using namespace std;
class Square{
    float sideLength;
    float area;
    static float allAreas;
    public:
    Square(){
        sideLength = 0;
    }
    Square(float side){
        sideLength = side;
    }
    float CalculateArea(float side){
        this->area = side * side;
        allAreas += area;
        return area;
    }
    float getArea(){
        return area;
    }
    static float getAllAreas(){
        return allAreas;
    }
    float getSide(){
        return sideLength;
    }
    void setSide(float side){
        this->sideLength = side;
    }

};

float Square::allAreas = 0;
int main(){
    Square s1(10),s2(20),s3(30);
    s1.CalculateArea(10);
    cout<<"Area of 1 : "<<s1.getArea()<<endl;
    cout<<"Area total: "<<s1.getAllAreas()<<endl;
s2.CalculateArea(20);
    cout<<"Area of 3 : "<<s2.getArea()<<endl;
    cout<<"Area total: "<<s1.getAllAreas()<<endl;
s3.CalculateArea(30);
    cout<<"Area of 2 : "<<s3.getArea()<<endl;
    cout<<"Area total: "<<s1.getAllAreas()<<endl;

}