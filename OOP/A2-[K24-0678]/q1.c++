#include <iostream>
using namespace std;
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
    virtual void printDetails()
    {

        cout << "Is Paid: " << ispaid << endl;
        cout << "Pickup: " << pickup << endl;
        cout << "Drop: " << drop << endl;
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
        Customer::printDetails();
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
        Customer::printDetails();
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
        stops = nullptr;
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
        if (NoCustomerAssigned < capacity)
        {
            bool pickupFound = false;
            bool dropFound = false;

            for (int i = 0; i < noStops; i++)
            {
                if (Customer->getPickup() == stops[i])
                {
                    pickupFound = true;
                    break;
                }
            }

            if (pickupFound)
            {
                for (int j = 0; j < noStops; j++)
                {
                    if (Customer->getDrop() == stops[j])
                    {
                        dropFound = true;
                        break;
                    }
                }
            }

            if (pickupFound && dropFound)
            {
                Customer->setIsPaid(true);
                NoCustomerAssigned++;
                Customer->setAssignedBus(this);
                cout << "Customer " << Customer->getName() << " has been assigned to bus " << BusId << endl;
            }
            else
            {
                cout << "Customer stop doesn't exist" << endl;
            }
        }
        else
        {
            cout << "Bus is full" << endl;
        }
    }
};
class TransportSystem
{
    Customer **customer;
    Bus *bus;
    int noCustomers;
    int noBuses;

public:
    Customer *getCustomer()
    {
        return *customer;
    }
    Bus *getBus()
    {
        return bus;
    }
    void setBus(Bus *bus)
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
            cout << "Bus ID: " << bus[i].getBusId() << ", Capacity: " << bus[i].getCapacity() << ", No of Customers: " << bus[i].getNoCustomersAssigned() << ", Stops: ";
            bus[i].printStops();
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

    void addBus(int id, int cap, string *stop, int noStops)
    {
        Bus *temp = new Bus[noBuses + 1];

        cout << "No Busses in Tranport : " << noBuses << endl;

        for (int i = 0; i < noBuses; i++)
        {
            temp[i] = bus[i];
        }

        temp[noBuses] = Bus(id, cap, stop, noStops);

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
        cout << "6. Exit" << endl;
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
            ts.addBus(busId, capacity, stops, n);
        }
        break;

        case 3:
        {
            cout << "Enter Customer index: ";
            int CustomerIndex;
            cin >> CustomerIndex;
            cout << "Enter bus index: ";
            int busIndex;
            cin >> busIndex;
            ts.getBus()[busIndex].AssignCustomer(&ts.getCustomer()[CustomerIndex]);
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