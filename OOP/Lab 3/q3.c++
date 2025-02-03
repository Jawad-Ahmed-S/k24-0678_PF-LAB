#include<iostream>
using namespace std;
class Serial{
    private:
    
    int serial;
    static int count;
    
    public:
    void Getter(){
        cout<<"Count is "<<count;
    }
    void SerialGenerator(){
        count++;
        serial = 100 + count;
    }
    void display(){
        SerialGenerator();
        cout<<" I am Object "<<serial<<endl;
    }
    };

    int Serial::count =0;

int main(){
    Serial S1,S2,S3;
    S1.display();
    S2.display();
    S3.display();

    S1.Getter();
}