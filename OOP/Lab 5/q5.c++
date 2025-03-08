#include <iostream>
using namespace std;
class Engine
{
public:
    void engine()
    {
        cout << "Engine is composed." << endl;
    }
};
class HeadLights
{
public:
    void headlights()
    {
        cout << "Headlights are composed." << endl;
    }
};
class Steering
{
public:
    void steering()
    {
        cout << "Steering wheel is aggregated." << endl;
    }
};
class Wheels
{
    int number;

public:
    void setNumber(int number)
    {
        this->number = number;
    }
    int getNumber()
    {
        return this->number;
    }
    void wheels()
    {
        cout << "Wheels are aggregated." << endl;

        cout << "Wheel no : " << this->number << endl;
    }
};
class Car
{
    Engine E;
    HeadLights H;
    Steering *s;
    Wheels *W;

public:
    Car(Steering *s, Wheels *w)
    {
        this->s = s;
        this->W = w;
    }
    void DisplayComponents()
    {
        E.engine();
        H.headlights();
        s->steering();
        for (int i = 0; i < 4; i++)
            W[i].wheels();
    }
    ~Car() {}
};
int main()
{
    Steering *s1 = new Steering;
    Wheels *w = new Wheels[4];
    w[0].setNumber(1);
    w[1].setNumber(2);
    w[2].setNumber(3);
    w[3].setNumber(4);

    Car c(s1, w);
    c.DisplayComponents();

    return 0;
}