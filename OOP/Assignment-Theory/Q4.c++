#include <iostream>
using namespace std;
class Bus;
class Student
{
    int StudentId;
    string Name;
    bool ispaid;
    string pickup;
    string drop;
    Bus *AssignedBus;

public:
    Student()
    {
        StudentId = 0;
        Name = "";
        ispaid = false;
        pickup = "";
        drop = "";
        this->AssignedBus = nullptr;
    }
    Student(int id, string name, bool paid, string pickup, string drop)
    {
        StudentId = id;
        Name = name;
        ispaid = paid;
        this->pickup = pickup;
        this->drop = drop;
        this->AssignedBus = nullptr;
    }
    int getStudentId()
    {
        return StudentId;
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
    void setIsPaid(bool paid)
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
class Bus
{
    int BusId;
    int capacity;
    string *stops;
    int NoStudentAssigned;
    int noStops;

public:
    Bus(int id, int cap, string *stop, int noStops)
    {
        BusId = id;
        capacity = cap;
        this->noStops = noStops; // Corrected: Assign to member variable
        stops = new string[noStops];
        for (int i = 0; i < noStops; i++)
        { // Corrected: loop to noStops
            stops[i] = stop[i];
        }
        NoStudentAssigned = 0;
    }

    Bus()
    {
        BusId = 0;
        capacity = 0;
        stops = nullptr;
        NoStudentAssigned = 0;
        noStops = 0;
    }

    Bus(const Bus &other)
    {
        cout << "\nBus ke copy constructor me";
        BusId = other.BusId;
        capacity = other.capacity;
        noStops = other.noStops;
        stops = new string[noStops];
        cout << "\ncopy constructor me stop ka loop";
        for (int i = 0; i < noStops; i++)
        {
            stops[i] = other.stops[i];
        }
        cout << "\n\ncopy constructor me stop ka loop after";
        NoStudentAssigned = other.NoStudentAssigned;
    }

    Bus &operator=(const Bus &other)
    {
        cout << "Assignment operator called for Bus: " << other.BusId << endl;
        if (this != &other)
        {
            delete[] stops;
            BusId = other.BusId;
            capacity = other.capacity;
            noStops = other.noStops;
            NoStudentAssigned = other.NoStudentAssigned;
            stops = new string[noStops];

            for (int i = 0; i < noStops; i++)
            {
                stops[i] = other.stops[i];
            }
        }
        return *this;
    }

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

    void setNoStudentsAssigned(int noStudentsAssigned)
    {
        this->NoStudentAssigned = noStudentsAssigned;
    }
    int getNoStudentsAssigned()
    {
        return NoStudentAssigned;
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
            cout << stops[i] << " ";
        }
        cout << endl;
    }
    void AssignStudent(Student *student)
    {
        if (NoStudentAssigned < capacity)
        {
            bool pickupFound = false;
            bool dropFound = false;

            for (int i = 0; i < noStops; i++)
            {
                if (student->getPickup() == stops[i])
                {
                    pickupFound = true;
                    break; // Exit the loop when pickup is found
                }
            }

            if (pickupFound)
            {
                for (int j = 0; j < noStops; j++)
                {
                    if (student->getDrop() == stops[j])
                    {
                        dropFound = true;
                        break; // Exit the loop when drop is found
                    }
                }
            }

            if (pickupFound && dropFound)
            {
                student->setIsPaid(true);
                NoStudentAssigned++;
                student->setAssignedBus(this);
                cout << "Student " << student->getName() << " has been assigned to bus " << BusId << endl;
            }
            else
            {
                cout << "Student stop doesn't exist" << endl;
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
    Student *student;
    Bus *bus;
    int noStudents;
    int noBuses;

public:
    Student *getStudent()
    {
        return student;
    }
    Bus *getBus()
    {
        return bus;
    }
    void setBus(Bus *bus)
    {
        this->bus = bus;
    }
    void SetStudent(Student *student)
    {
        this->student = student;
    }
    TransportSystem(int n)
    {

        noStudents = n;
        noBuses = 0;
        student = new Student[n];
        bus = new Bus[n];
    }
    void addStudent(string name, bool paid, string pickup, string drop)
    {
        Student *temp = new Student[noStudents + 1];

        for (int i = 0; i < noStudents; i++)
        {
            temp[i] = student[i];
        }
        temp[noStudents] = Student(noStudents + 1, name, paid, pickup, drop); // Properly initialize

        delete[] student;
        student = temp;
        noStudents++;
    }
    void addBus(int id, int cap, string *stop, int noStops)
    {
        cout << "addBus";
        cout << "No Busses in Tranport : " << noBuses << endl;
        Bus *temp = new Bus[noBuses + 1];

        cout << "No Busses in Tranport : " << noBuses << endl;

        for (int i = 0; i < noBuses; i++)
        {
            temp[i] = bus[i];
        }

        cout << "temp[]noBusses in Tranport" << endl;
        cout << "No Busses in Tranport : " << noBuses << endl;
        temp[noBuses] = Bus(id, cap, stop, noStops);

        cout << "temp[]noBusses in Tranport after adding new bus" << endl;
        delete[] bus;
        bus = temp;
        noBuses++;
    }
};

Bus *Student::getAssignedBus()
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
    TransportSystem ts(5);
    cout << "Checking Bus Pointer: " << ts.getBus() << endl;
    cout << "Checking Student Pointer: " << ts.getStudent() << endl;

    int choice;
    string name;
    int capacity;
    string pickup;
    string drop;

    while (true)
    {
        cout << "Main Menu" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Bus" << endl;
        cout << "3. Assign Bus" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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
            ts.addStudent(name, false, pickup, drop);
        }
        break;

        case 2:
        {
            cout << "Enter bus ID: ";
            int busId;
            cin >> busId;
            cout << "Enter capacity: ";
            cin >> capacity;
            cout << "Enter number of stops: ";
            int n;
            cin >> n;
            string *stops = new string[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Enter stop: ";
                cin >> stops[i];
            }
            ts.addBus(busId, capacity, stops, n);
            cout << "outside main loop" << endl;
        }
        break;

        case 3:
        {
            cout << "Enter student index: ";
            int studentIndex;
            cin >> studentIndex;
            cout << "Enter bus index: ";
            int busIndex;
            cin >> busIndex;
            ts.getBus()[busIndex].AssignStudent(&ts.getStudent()[studentIndex]);
        }
        break;
            break;

            break;

        case 4:
            cout << ts.getStudent()[0].getAssignedBus();
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}