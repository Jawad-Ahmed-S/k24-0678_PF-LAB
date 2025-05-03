#include <iostream>
using namespace std;
#include <fstream>

class AssignmentInfo
{
    string name;
    string id;

public:
    AssignmentInfo()
    {
        name = "Jawad Ahmed";
        id = "K24-0678";
    }
    void WhoDidAssignment()
    {
        cout << "\n\nThe assignment was created by " << name << " (" << id << ")\n"
             << endl;
    }
};

int getValidInt()
{
    int value;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> value;

        if (cin.fail())
        {
            cin.clear();            // Clear the error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a valid number.\n";
        }
        else
        {
            cin.ignore(1000, '\n'); // Clear any extra characters (like letters after numbers)
            return value;           // Return valid input
        }
    }
}
class Bus;
class Customer
{
protected:
    int CustomerId;
    string Name;
    bool ispaid;
    string pickup;
    string drop;
    int CardActiveMonths;
    Bus *AssignedBus;

public:
    Customer()
    {
        CustomerId = 0;
        Name = "";
        ispaid = false;
        pickup = "";
        drop = "";
        this->AssignedBus = nullptr;
    }
    Customer(int id, string name, bool paid, string pickup, string drop, int monthsPaid)
    {
        CustomerId = id;
        Name = name;
        ispaid = paid;
        this->pickup = pickup;
        this->drop = drop;
        this->AssignedBus = nullptr;
        CardActiveMonths = monthsPaid;
    }
    virtual void printDetails()=0;
    virtual void saveDataToFile(){
        ofstream outFile;
        outFile.open("Customers.bin", ios::app);
        outFile << CustomerId << " " << Name << " " << ispaid << " " << pickup << " " << drop << " " << CardActiveMonths << endl;
        outFile.close();
    } 
    int getCustomerId()
    {
        return CustomerId;
    }
    string getName()
    {
        return Name;
    }
    void setName(string name)
    {
        this->Name = name;
    }
    bool getIsPaid()
    {
        return ispaid;
    }
    string getPickup()
    {
        return pickup;
    }
    string getDrop()
    {
        return drop;
    }
    virtual void setIsPaid(bool paid)
    {
        ispaid = paid;
    }
    void setPickup(string pickup)
    {
        this->pickup = pickup;
    }
    void setDrop(string drop)
    {
        this->drop = drop;
    }
    Bus *getAssignedBus();
    void setAssignedBus(Bus *bus)
    {
        this->AssignedBus = bus;
    }
};
class Student : public Customer
{
public:
    Student(int id, string name, bool ispaid, string pickup, string drop) : Customer(id, name, ispaid, pickup, drop, 6) {}
    void setIsPaid(bool paid) override
    {
        ispaid = paid;
        CardActiveMonths = 6;
    }
    void printDetails() override
    {
        cout << "\nStudent ID: " << CustomerId << endl;
        cout << "Student Name: " << Name << endl;
        cout << "Is Paid: " << ispaid << endl;
        cout << "Pickup: " << pickup << endl;
        cout << "Drop: " << drop << endl;
        cout << "Card Active Months: "
             << CardActiveMonths << endl
             << endl;
    }
};
class Teacher : public Customer
{
public:
    Teacher(int id, string name, bool ispaid, string pickup, string drop) : Customer(id, name, ispaid, pickup, drop, 1) {}
    void setIsPaid(bool paid) override
    {
        ispaid = paid;
        CardActiveMonths = 1;
    }
    void printDetails() override
    {
        cout << "\nTeacher ID: " << CustomerId << endl;
        cout << "Teacher Name: " << Name << endl;
        cout << "Is Paid: " << ispaid << endl;
        cout << "Pickup: " << pickup << endl;
        cout << "Drop: " << drop << endl;
        cout << "Card Active Months: \n"
             << CardActiveMonths << endl;
    }
};
class Bus
{
    int BusId;
    int capacity;
    string *stops;
    int NoCustomerAssigned;
    int noStops;

public:
    Bus(int id, int cap, string *stop, int noStops)
    {
        BusId = id;
        capacity = cap;
        this->noStops = noStops;
        stops = new string[noStops];
        for (int i = 0; i < noStops; i++)
        {
            stops[i] = stop[i];
        }
        NoCustomerAssigned = 0;
    }

    Bus()
    {
        BusId = 0;
        capacity = 0;
        for (int i = 0; i < noStops; i++)
        {
            stops[i] = nullptr;
        }
        NoCustomerAssigned = 0;
        noStops = 0;
    }

    Bus(const Bus &other)
    {
        cout << "\nBus ke copy constructor me";
        BusId = other.BusId;
        capacity = other.capacity;
        noStops = other.noStops;
        stops = new string[noStops];
        NoCustomerAssigned = other.NoCustomerAssigned;
        for (int i = 0; i < noStops; i++)
        {
            stops[i] = other.stops[i];
        }
    }

    // Bus &operator=(const Bus &other)
    // {
    //     cout << "Assignment operator called for Bus: " << other.BusId << endl;
    //     if (this != &other)
    //     {
    //         delete[] stops;
    //         BusId = other.BusId;
    //         capacity = other.capacity;
    //         noStops = other.noStops;
    //         NoCustomerAssigned = other.NoCustomerAssigned;
    //         stops = new string[noStops];

    //         for (int i = 0; i < noStops; i++)
    //         {
    //             stops[i] = other.stops[i];
    //         }
    //     }
    //     return *this;
    // }

    ~Bus()
    {
        delete[] stops;
    }
    int getBusId()
    {
        return BusId;
    }
    int getCapacity()
    {
        return capacity;
    }
    string *getStops()
    {
        return stops;
    }
    void setNoStops(int stops)
    {
        this->noStops = stops;
    }
    int getNoStops()
    {
        return noStops;
    }
    void setStops(string *stop, int noStops)
    {
        delete[] stops;
        this->noStops = noStops;
        stops = new string[noStops];
        for (int i = 0; i < noStops; i++)
        {
            stops[i] = stop[i];
        }
    }

    void setNoCustomersAssigned(int noCustomersAssigned)
    {
        this->NoCustomerAssigned = noCustomersAssigned;
    }
    int getNoCustomersAssigned()
    {
        return NoCustomerAssigned;
    }
    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }
    void setBusId(int busId)
    {
        this->BusId = busId;
    }
    void printStops()
    {
        for (int i = 0; i < noStops; i++)
        {
            cout << "\n"
                 << i + 1 << ". " << stops[i];
        }
        cout << endl;
    }
    void AssignCustomer(Customer *Customer)
{
    cout << "AssignCustomer called for Customer: " << Customer->getName() << endl;
    cout << "Checking if Bus ID " << BusId << " has available seats..." << endl;

    if (NoCustomerAssigned < capacity)
    {
        bool pickupFound = false;
        bool dropFound = false;

        cout << "Bus Capacity: " << capacity << ", Currently Assigned: " << NoCustomerAssigned << endl;
        cout << "Checking pickup stop: " << Customer->getPickup() << endl;

        for (int i = 0; i < noStops; i++)
        {
            cout << "Checking bus stop: " << stops[i] << endl;
            if (Customer->getPickup() == stops[i])
            {
                cout << "Pickup stop matched: " << stops[i] << endl;
                pickupFound = true;
                break;
            }
        }

        if (!pickupFound)
        {
            cout << "Pickup stop not found for Customer: " << Customer->getName() << endl;
        }

        if (pickupFound)
        {
            cout << "Checking drop stop: " << Customer->getDrop() << endl;
            for (int j = 0; j < noStops; j++)
            {
                cout << "Checking bus stop: " << stops[j] << endl;
                if (Customer->getDrop() == stops[j])
                {
                    cout << "Drop stop matched: " << stops[j] << endl;
                    dropFound = true;
                    break;
                }
            }

            if (!dropFound)
            {
                cout << "Drop stop not found for Customer: " << Customer->getName() << endl;
            }
        }

        if (pickupFound && dropFound)
        {
            cout << "Both pickup and drop found. Assigning customer..." << endl;
            Customer->setIsPaid(true);
            NoCustomerAssigned++;
            Customer->setAssignedBus(this);
            cout << "Customer " << Customer->getName() << " has been assigned to Bus " << BusId << endl;
        }
        else
        {
            cout << "Either pickup or drop stop is missing. Customer not assigned." << endl;
        }
    }
    else
    {
        cout << "Bus is full. Cannot assign customer." << endl;
    }
}

};
class TransportSystem
{
    Customer **customer;
    Bus **bus;
    int noCustomers;
    int noBuses;

public:
    Customer **getCustomer()
    {
        return customer;
    }
    Bus **getBus()
    {
        return bus;
    }
    void setBus(Bus **bus)
    {
        this->bus = bus;
    }
    void SetCustomer(Customer **customer)
    {
        this->customer = customer;
    }
    TransportSystem()
    {

        noCustomers = 0;
        noBuses = 0;
        customer = nullptr;
        bus = nullptr;
    }
    void printAllCustomers()
    {
        if (noCustomers == 0)
        {
            cout << "No Customers found\n"
                 << endl;
            return;
        }
        cout << "\nAll Customers: \n";
        for (int i = 0; i < noCustomers; i++)
        {
            customer[i]->printDetails();
        }
    }
    void printAllBuses()
    {
        if (noBuses == 0)
        {
            cout << "No buses found\n"
                 << endl;
            return;
        }
        cout << "\nAll Buses: \n";
        for (int i = 0; i < noBuses; i++)
        {
            cout << "Bus ID: " << bus[i]->getBusId() << ", Capacity: " << bus[i]->getCapacity() << ", No of Customers: " << bus[i]->getNoCustomersAssigned() << ", Stops: ";
            bus[i]->printStops();
        }
    }
    void addCustomer(string name, bool paid, string pickup, string drop, string Type)
    {
        Customer **temp = new Customer *[noCustomers + 1]; // ✅ Allocate array of pointers

        for (int i = 0; i < noCustomers; i++)
        {
            temp[i] = customer[i]; // ✅ Copy existing pointers
        }

        if (Type == "student")
        {
            temp[noCustomers] = new Student(noCustomers + 1, name, paid, pickup, drop); // ✅ Use new
        }
        else if (Type == "teacher")
        {
            temp[noCustomers] = new Teacher(noCustomers + 1, name, paid, pickup, drop); // ✅ Use new
        }

        delete[] customer; // ✅ Free old array (but don't delete objects)
        customer = temp;
        noCustomers++;
    }

void addBus(int id, int cap, string* stop, int noStops)
{
    Bus** temp = new Bus*[noBuses + 1];
    
    // Copy existing buses
    for (int i = 0; i < noBuses; i++)
    {
        temp[i] = bus[i];
    }
    
    // Create new bus
    temp[noBuses] = new Bus(id, cap, stop, noStops);
    
    // Delete old array (but not the Bus objects)
        delete[] bus;
    
    
    bus = temp;
    noBuses++;
}


};

Bus *Customer::getAssignedBus()
{
    if (AssignedBus)
    {

        cout << "Assigned Bus: " << AssignedBus->getBusId() << endl;
        return AssignedBus;
    }
    else
        cout << "No bus assigned yet." << endl;
    return nullptr;
}
int main()
{
    AssignmentInfo assignment;
    assignment.WhoDidAssignment();
    TransportSystem ts;
    int choice;
    string name;
    int capacity;
    string pickup;
    string drop;

    while (true)
    {
        cout << "Main Menu" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Add Bus" << endl;
        cout << "3. Assign Bus" << endl;
        cout << "4. All Customers" << endl;
        cout << "5. All Buses" << endl;
        cout << "6. Pay Fee" << endl;
        cout << "7. Exit" << endl;
        choice = getValidInt();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter pickup location: ";
            cin >> pickup;
            cout << "Enter drop location: ";
            cin >> drop;
            cout << "Student / Teacher (lowercase)";
            string Type;
            cin >> Type;
            ts.addCustomer(name, false, pickup, drop, Type);
        }
        break;

        case 2:
        {
            cout << "Enter bus ID: (integer)";
            int busId;
            cin >> busId;
            cout << "Enter capacity: (integer)";
            cin >> capacity;
            cout << "Enter number of stops: (Integer greater than 0)";
            int n;
            cin >> n;

            string *stops = new string[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Enter stop: ";
                cin >> stops[i];
            }
            cout << "Bus added in TS" << endl;
            ts.addBus(busId, capacity, stops, n);
        }
        break;

        case 3:
        {
            ts.printAllBuses();
            ts.printAllCustomers();
            cout << "Enter Customer index: ";
            int CustomerIndex;
            cin >> CustomerIndex;
            cout << "Enter bus index: ";
            int busIndex;
            cin >> busIndex;
            Customer* custPtr = ts.getCustomer()[CustomerIndex];
            cout<<"after custPtr\n";
            custPtr->printDetails();
            cout<<"after custPtr\n";

            ts.getBus()[busIndex]->AssignCustomer(custPtr);
            cout<<"after getBus\n";
            }
        break;
        case 4:
            ts.printAllCustomers();
            break;
        case 5:
            ts.printAllBuses();
            break;
        case 6:
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    
    return 0;
}