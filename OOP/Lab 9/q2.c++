#include<iostream>
using namespace std;
class SmartDevice{
    protected:
    bool isOn;
    public:
    SmartDevice(bool ison){
        isOn = ison;
    }
    virtual void turnOn()=0;
    virtual void turnOff()=0;   
    virtual bool GetStatus()=0;
};
class LightBulb:public SmartDevice{
    int brightness;
    public:
    LightBulb(int brightness):brightness(brightness),SmartDevice(false){};
    void turnOn()override{
        isOn = true;
    }
    void turnOff()override{
        isOn = false;
    }
    bool GetStatus()override{
        return isOn;
    }
};
class Thermostat:public SmartDevice{
    double temperature;
    public:
    Thermostat(double temp):temperature(temp),SmartDevice(false){};
    void turnOn()override{
        isOn = true;
    }
    void turnOff()override{
        isOn = false;
    }
    bool GetStatus()override{
        return isOn;
    }
};
int main(){
   LightBulb l(50);
   Thermostat t(25.5);
   l.turnOn();
   t.turnOn();
   cout<<l.GetStatus()<<endl;
   cout<<t.GetStatus()<<endl;
    return 0;
}
