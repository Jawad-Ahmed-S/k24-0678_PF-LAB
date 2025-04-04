#include <iostream>
using namespace std;
class Ghost
{
protected:
    int RNG;
    string nameWorker;
    int ScareLevel;

public:
    Ghost()
    {
        RNG = 0;
        nameWorker = "";
        ScareLevel = 0;
    }
    int getRNG() const
    {
        return RNG;
    }
    string getName() const
    {
        return nameWorker;
    }
    int getScarelevel() {
        return ScareLevel;
    }
    Ghost(int rng, string name)
    {
        RNG = rng;
        nameWorker = name;
        ScareLevel = 0;
    }
    virtual void Haunting() {};
    virtual ~Ghost() {};
    friend ostream &operator<<(ostream &os, const Ghost &ghost);
    virtual Ghost *operator+(Ghost &ghost) = 0;
};
ostream &operator<<(ostream &os, const Ghost &ghost)
{
    os << "Ghost: " << ghost.nameWorker << ", RNG: " << ghost.RNG << ", Scare level: " << ghost.ScareLevel << endl;
    return os;
}
// Ghost operator+(Ghost &ghost)
// {
//     return Ghost(ghost.RNG*2,ghost.nameWorker);
// }
class Poltergiests : virtual public Ghost
{
public:
    Poltergiests(int rng, string name) : Ghost(rng, name)
    {
        ScareLevel = 4;
    }
    void Haunting() override
    {
        cout << nameWorker << "(Poltergeist)  haunts by moving objects. Scare level: " << ScareLevel << endl;
    }
    Ghost *operator+(Ghost &ghost) override
    {
        return new Poltergiests(ghost.getRNG(), ghost.getName());
    }
};
class Banshees : virtual public Ghost
{
public:
    Banshees(int rng, string name) : Ghost(rng, name)
    {
        ScareLevel = 6;
    }
    void Haunting() override
    {
        cout << nameWorker << "(Banshee)  haunts by making loud noises. Scare level: " << ScareLevel << endl;
    }
    Ghost *operator+(Ghost &ghost) override
    {
        cout<<"Ghost in Banshees +";
        Banshees *tempghost = new Banshees(*this);      // Create copy of current object
        tempghost->RNG += ghost.getRNG();               // Sum RNG values
        tempghost->nameWorker += "+" + ghost.getName(); // Combine names
        tempghost->ScareLevel += ghost.getScarelevel(); // Sum scare levels
        return tempghost;
    }
    // In Banshees class
    Banshees operator+()
    {
        cout<<"Banshees +";
        return Banshees(RNG * 2, "Boosted_" + nameWorker); // Doubles RNG
    }
};
class ShadowGhosts : virtual public Ghost
{
public:
    ShadowGhosts(int rng, string name) : Ghost(rng, name)
    {
        ScareLevel = 9;
    }
    void Haunting() override
    {
        cout << nameWorker << "(Shadow)  haunts by whisper creeping. Scare level: " << ScareLevel << endl;
    }
    Ghost *operator+(Ghost &ghost) override
    {
        cout << "Ghost in Banshees +";
        ShadowGhosts *tempghost = new ShadowGhosts(*this);      // Create copy of current object
        tempghost->RNG = 2;               // Sum RNG values
        tempghost->nameWorker += "+" + ghost.getName(); // Combine names
        tempghost->ScareLevel += ghost.getScarelevel(); // Sum scare levels
        return tempghost;
    }
    
};
class HybridGhosts : virtual public ShadowGhosts, virtual public Poltergiests
{
public:
    HybridGhosts(int rng, string name) : Ghost(rng, name), ShadowGhosts(rng, name), Poltergiests(rng, name) {};
    void Haunting() override
    {
        cout << nameWorker << "(Hybrid)  haunts by moving objects, making loud noises, and whisper creeping. Scare level: " << ScareLevel << endl;
        // cout << nameWorker << "(Shadow)  haunts by whisper creeping. Scare level: " << ScareLevel << endl;
    }
    Ghost *operator+(Ghost &ghost) override
    {
        return new HybridGhosts(ghost.getRNG(), ghost.getName());
    }
};
class HauntedHouse
{
    Ghost **ghost;
    int ghostLength;

public:
    // Poltergiests p1;
    // Banshees b1;
    // ShadowGhosts s1;
    // HybridGhosts h1;
    // public:
    Ghost **getGhost()
    {
        return ghost;
    }
    int getLengthGhost()
    {
        return ghostLength;
    }
    HauntedHouse()
    {
        ghostLength = 0;
        ghost = new Ghost *[ghostLength];
    };
    void addGhost(Ghost *g)
    {
        Ghost **temp = new Ghost *[ghostLength + 1];
        for (int i = 0; i < ghostLength; i++)
            temp[i] = ghost[i];

        temp[ghostLength] = g;
        ghostLength++;
        delete[] ghost;
        ghost = temp;
    }
    // Poltergiests getPolt(){
    //     return p1;
    // }
    // Banshees getBan(){
    //     return b1;
    // }
    // ShadowGhosts getSha(){
    //     return s1;
    // }
    // HybridGhosts getHyp(){
    //     return h1;
    // }
    void StartHaunting()
    {
        // p1.Haunting();
        // b1.Haunting();
        // s1.Haunting();
        // h1.Haunting();
        for (int i = 0; i < ghostLength; i++)
        {
            ghost[i]->Haunting();
            // Visits();
        }
    };
    void friend Visits()
    {
    }
};
class Visitors
{
    string name;
    int BraveryScale;
    string Brave;

public:
    string getName()
    {
        return name;
    }
    int getBravery()
    {
        return BraveryScale;
    }

    Visitors(string name, int bravery)
    {
        this->name = name;
        this->BraveryScale = bravery;
        if (BraveryScale >= 8 && BraveryScale <= 10)
        {
            Brave = "Fearless";
        }
        else if (BraveryScale >= 5 && BraveryScale < 8)
        {
            Brave = "Brave";
        }
        else if (BraveryScale >= 1 && BraveryScale < 5)
        {
            Brave = "Cautious";
        }
    }
};
void Visits(Visitors *v, HauntedHouse h, int VLength)
{
    // Ghost **ptr = h.getGhost();

    for (int i = 0; i < VLength; i++)
    {
        cout << "Visitor: " << v[i].getName() << ", Bravery: " << v[i].getBravery() << endl;
        for (int j = 0; j < h.getLengthGhost(); j++)
        {
            cout << h.getGhost()[j]->getName() << endl;
            if (v[i].getBravery() > h.getGhost()[j]->getRNG())
            {
                cout << "Laughs" << endl;
            }
            else if (v[i].getBravery() < h.getGhost()[j]->getRNG())
            {
                cout << "Screams and runs away" << endl;
            }
            else
            {
                cout << "Gets a Shaky Voice" << endl;
            }
        }
    }
};
int main()
{
    Visitors v1("Tom", 8);
    Visitors v2("Mike", 6);
    Visitors VisitorArray[2] = {v1, v2};
    Poltergiests p1(3, "Tom");
    Banshees b1(5, "Mike");
    ShadowGhosts s1(10, "Tom");
    HybridGhosts h1(10, "Mike");

    HauntedHouse h;
    h.addGhost(&p1);
    h.addGhost(&h1);

    Visits(VisitorArray, h, 2);
    h.StartHaunting();
    cout << b1;
    // Banshees bs(4,"BansheeTest")
    Banshees bs = +b1;
    cout << bs;
    return 0;
}
