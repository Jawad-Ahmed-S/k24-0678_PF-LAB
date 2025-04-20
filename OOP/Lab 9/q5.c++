#include<iostream>
using namespace std;
class Activity{
    protected:
    virtual double calculateCaloriesBurned()=0;
};
class Cycling: public Activity{
    double speed;
    double time;
    float caloriesBurnedInUnit;
    public:
    Cycling(double t,double s,float c):speed(s),time(t),caloriesBurnedInUnit(c){};
    double calculateCaloriesBurned() override{
        return time*speed*caloriesBurnedInUnit;
    }
};
class Running :public Activity{
    double distance;
    double time;
    float caloriesBurnedInUnit;
    public:
    Running(double d,double t,float c):distance(d),time(t),caloriesBurnedInUnit(c){};
    double calculateCaloriesBurned() override{
        return distance*time*caloriesBurnedInUnit;
    }
};
int main() {
    Running r(2.5, 30, 0.05);
    Cycling c(1.5, 45, 0.08);
    cout << "Calories burned cycling: " << c.calculateCaloriesBurned() << " calories" << endl;
    cout << "Calories burned running: " << r.calculateCaloriesBurned() << " calories" << endl;
     
 
    return 0;
}