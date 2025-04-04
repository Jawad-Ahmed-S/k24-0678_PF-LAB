#include <iostream>
#include <math.h>
using namespace std;
class ConflictResolution;
class System;
class vehicle
{
protected:
    int speed;
    int capacity;
    int energyEfficiency;
    int vehicleId;
    int static NoDeliviries;

public:
    vehicle(int speed, int capacity, int energyEfficiency, int id)
    {
        this->speed = speed;
        this->capacity = capacity;
        this->energyEfficiency = energyEfficiency;
        this->vehicleId = id;
    }
    void DeliveryRoute()
    {
    }

    virtual double CalcDistance(int x1, int y1, int x2, int y2)
    {
        int distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        return distance;
    }
    virtual double CalTime(double distance, int penaltyItems)
    {
        double time = distance / speed;
        time += penaltyItems * 0;
        cout << "Time: " << time << " hours" << endl;
        return time;
    }
    friend class ConflictResolution;
    friend class System;
};
class RamzanDrone : public vehicle
{
public:
    RamzanDrone(int id) : vehicle(4, 1, 9, id) {};
    double CalcDistance(int x1, int y1, int x2, int y2) override
    {
        int distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        cout << "Ramzan Drone Distance: " << distance << " km" << endl;
        return distance;
    }
    double CalTime(double distance, int penaltyItems) override
    {
        double time = distance / speed;
        time += penaltyItems * 0.1;
        cout << "Time: " << time << " hours" << endl;
        return time;
    }
};
class RamzanTimeShip : public vehicle
{
public:
    RamzanTimeShip(int id) : vehicle(10, 10, 1, id) {};
    double CalcDistance(int x1, int y1, int x2, int y2) override
    {
        int SpaceDistance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double penalty = 10;
        return SpaceDistance + penalty;
        cout << "Ramzan Time Ship Distance: " << SpaceDistance + penalty << " km" << endl;
    }
    double CalTime(double distance, int penaltyItems) override
    {
        double time = distance / speed;
        time += penaltyItems * 0.5;
        cout << "Time: " << time << " hours" << endl;
        return time;
    }
};
class RamzanHyperPod : public vehicle
{
public:
    RamzanHyperPod(int id) : vehicle(20, 20, 2, id) {};
    double CalcDistance(int x1, int y1, int x2, int y2) override
    {
        double euclideanDist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        return euclideanDist + (rand() % 10);
    }
    double CalTime(double distance, int penaltyItems) override
    {
        double time = distance / speed;
        time += penaltyItems * 0;
        cout << "Time: " << time << " hours" << endl;
        return time;
    }
};
class Package
{
public:
    int weight;
    string urgency;
    int Destx;
    int Desty;
    Package(int weight, string urgency, int x, int y)
    {
        this->weight = weight;
        this->urgency = urgency;
        this->Destx = x;
        this->Desty = y;
    }
};
class ConflictResolution
{
public:
    static vehicle &resolveConflict(vehicle &v1, vehicle &v2, Package *p)
    {
        double distance1 = v1.CalcDistance(0, 0, p->Destx, p->Desty);
        double distance2 = v2.CalcDistance(0, 0, p->Destx, p->Desty);

        double time1 = v1.CalTime(distance1, p->weight);
        double time2 = v2.CalTime(distance2, p->weight);

        // Scoring System: Lower time and higher speed are prioritized
        double score1 = (time1 * 2) + (v1.speed * -1) + (v1.capacity * -0.5) + (v1.energyEfficiency * -0.2);
        double score2 = (time2 * 2) + (v2.speed * -1) + (v2.capacity * -0.5) + (v2.energyEfficiency * -0.2);

        return (score1 < score2) ? v1 : v2;
    }
};
class System
{
    Package **p;
    int pLength;

public:
    System(Package **p, int pLength)
    {
        this->p = p;
        this->pLength = pLength;
    }
    void command(string command, int index)
    {
        if (command == "Deliver")
        {
            vehicle *v = AssignVehicle(p[index]);
            int vId = v->vehicleId;
            cout << "Assigned vehicle: " << vId << endl;
            if(vId >= 100 and vId <200){
                cout << "Ramzan Drone is being used." << endl;
            }
            else if(vId >= 200 and vId <300){
                cout << "Ramzan Hyperpod is being used." << endl;
            }
            else if(vId >= 300 and vId <400){
                cout << "Ramzan Time Ship is being used." << endl;
            }
            else{
                cout<<"no vehicle..";
            }
            v->DeliveryRoute();
        }
        // v->CalTime(v->CalcDistance(0, 0, p[index]->Destx, p[index]->Desty), p[index]->weight);
    }
    vehicle *AssignVehicle(Package *p)
    {
        vehicle *selectedVehicle = nullptr;

        // Creating objects inside the function
        RamzanDrone drone(101);
        RamzanHyperPod hyperPod(201);
        RamzanTimeShip timeShip(301);

        bool droneQualifies = (drone.speed >= 10);
        bool hyperPodQualifies = (hyperPod.speed >= 10);
        bool timeShipQualifies = (timeShip.speed >= 10);

        if (droneQualifies && !hyperPodQualifies && !timeShipQualifies)
        {
            selectedVehicle = &drone;
        }
        else if (hyperPodQualifies && !droneQualifies && !timeShipQualifies)
        {
            selectedVehicle = &hyperPod;
        }
        else if (timeShipQualifies && !droneQualifies && !hyperPodQualifies)
        {
            selectedVehicle = &timeShip;
        }
        else if (droneQualifies && hyperPodQualifies)
        {
            vehicle &bestVehicle = ConflictResolution::resolveConflict(drone, hyperPod, p);
            selectedVehicle = &bestVehicle;
        }
        else if (droneQualifies && timeShipQualifies)
        {
            vehicle &bestVehicle = ConflictResolution::resolveConflict(drone, timeShip, p);
            selectedVehicle = &bestVehicle;
        }
        else if (hyperPodQualifies && timeShipQualifies)
        {
            vehicle &bestVehicle = ConflictResolution::resolveConflict(hyperPod, timeShip, p);
            selectedVehicle = &bestVehicle;
        }
        else if (droneQualifies && hyperPodQualifies && timeShipQualifies)
        {
            vehicle &bestVehicle = ConflictResolution::resolveConflict(drone, hyperPod, p);
            vehicle &finalChoice = ConflictResolution::resolveConflict(bestVehicle, timeShip, p);
            selectedVehicle = &finalChoice;
        }

        return selectedVehicle; // Return the selected vehicle pointer
    }
};
int main()
{
    Package **p;
    p = new Package *[3];
    p[0] = new Package(2, "high", 10, 10);
    p[1] = new Package(5, "medium", 15, 15);
    p[2] = new Package(3, "low", 20, 20);

    System s(p, 3);
    s.AssignVehicle(p[2]);
    s.command("Deliver", 2);
    delete[] p; // Deleting the dynamically allocated memory

    return 0;
}