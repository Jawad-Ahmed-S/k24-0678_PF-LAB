#include <iostream>
using namespace std;
class Time{
    int hours;
    int minutes;
    int seconds;

    public:
    Time(){
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    Time(int hours, int minutes, int seconds){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    void DisplayTime(Time t3){
        cout << "Time: " << t3.hours << ":" << t3.minutes << ":" << t3.seconds << endl;
        return;
    }
    Time AddTime(Time t2){
        Time t3;
         t3.seconds =   seconds + t2.seconds;
         t3.minutes =   minutes + t2.minutes;  
         t3.hours =   hours + t2.hours;
         return t3;
    }
};
int main(){
    Time();
    Time O1(4,50,35);
    Time O2(5,20,3);
    Time O3;
    O3 = O1.AddTime(O2);
    O3.DisplayTime(O3);
}