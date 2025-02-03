#include<iostream>
#include<iomanip>
using namespace std;
class Location{
    int degree;
    float minutes;
    char DirectionalLetter;

public:
    Location(int degree, float minutes, char DirectionalLetter){
        this->degree = degree;
        this->minutes = minutes;
        this->DirectionalLetter = DirectionalLetter;
    }
    void Validate(int degree,float minutes,char DirectionalLetter){
        if(degree<0 || degree>180){
            cout<<"Invalid Degree. Degree should be between 0 and 90."<<endl;
            exit(0);
        }
        if(minutes<0 || minutes>60){
            cout<<"Invalid Minutes. Minutes should be between 0 and 60."<<endl;
            exit(0);
        }
        if(DirectionalLetter!='N' && DirectionalLetter!='S' && DirectionalLetter!='E' && DirectionalLetter!='W' &&DirectionalLetter!='n' && DirectionalLetter!='s' && DirectionalLetter!='e' && DirectionalLetter!='w'){
            cout<<"Invalid Directional Letter. Directional Letter should be either N/S/E/W."<<endl;
            exit(0);
        }
    }
    void InputVariables(){
        cout<<"Enter Degree: ";
        cin>>degree;
        cout<<"Enter Minutes: ";
        cin>>minutes;
        cout<<"Enter Directional Letter (N/S/E/W): ";
        cin>>DirectionalLetter;
        Validate(degree, minutes, DirectionalLetter);
    }
    void OutputLocation(){
        cout<<"Location : "<<degree<<"\xF8,"<<minutes<<"'"<<DirectionalLetter<<endl;
    }
};
int main(){
    while(1){
    Location location(150,60.5,'E');
    location.InputVariables();
    location.OutputLocation();

    }

}