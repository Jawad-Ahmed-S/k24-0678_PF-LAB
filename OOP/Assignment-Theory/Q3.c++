#include <iostream>
#include <cstring>
using namespace std;
string ToLower(string str)
{
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
class User
{
    string name;
    int age;
    string contactNumber;
    string licenseType;
    int UserId;

public:
    User()
    {
        name = "";
        age = 0;
        contactNumber = "";
        licenseType = "";
        UserId = 0;
    }
    User(string name, int age, string contactNumber, string licenseType, int UserId)
    {
        this->name = name;
        this->age = age;
        this->contactNumber = contactNumber;
        this->licenseType = licenseType;
        this->UserId = UserId;
    }
    void setDetails(string name, int age, string contactNumber, string licenseType, int UserId)
    {
        this->name = name;
        this->age = age;
        this->contactNumber = contactNumber;
        this->licenseType = licenseType;
        this->UserId = UserId;
    }
    void setLicenseType(string licenseType)
    {
        this->licenseType = licenseType;
    }
    string getLicenseType()
    {
        return licenseType;
    }
    void displayUserDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "License Type: " << licenseType << endl;
        cout << "User ID: " << UserId << endl;
    }

    void UpdateUserDetails(string name, int age, string contactNumber, string licenseType)
    {
        this->name = name;
        this->age = age;
        this->contactNumber = contactNumber;
        this->licenseType = licenseType;
    }
};

class Vehicle
{
    string model;
    double rentalPricePerDay;
    string requiredLicenseType;

public:
    void setVehicleDetails(string model, double rentalPricePerDay, string requiredLicenseType)
    {
        this->model = model;
        this->rentalPricePerDay = rentalPricePerDay;
        this->requiredLicenseType = requiredLicenseType;
    }

    string getModel()
    {
        return model;
    }
    void setModel(string model)
    {
        this->model = model;
    }
    void setRentalPrice(double price)
    {
        this->rentalPricePerDay = price;
    }
    void setRequiredLicenseType(string requiredLicenseType)
    {
        this->requiredLicenseType = requiredLicenseType;
    }
    double getRentalPricePerDay()
    {
        return rentalPricePerDay;
    }

    string getRequiredLicenseType()
    {
        return requiredLicenseType;
    }

    void displayVehicleDetails()
    {
        cout << "Model: " << model << endl;
        cout << "Rental Price per Day: $" << rentalPricePerDay << endl;
        cout << "Required License Type: " << requiredLicenseType << endl;
    }
};

class RentalSystem
{
    User **user;
    Vehicle **vehicle;
    int usersSize;
    int vehiclesSize;

public:
    RentalSystem()
    {
        usersSize = 0;
        vehiclesSize = 0;
        this->user = nullptr;
        this->vehicle = nullptr;
    }

    void addUser(User *newUser)
    {
        User **temp = new User *[usersSize + 1];
        for (int i = 0; i < usersSize; i++)
        {
            temp[i] = this->user[i];
        }
        temp[usersSize] = newUser;
        usersSize++;
        delete[] this->user;
        this->user = temp;
    }

    void addVehicle(Vehicle *newVehicle)
    {
        Vehicle **temp = new Vehicle *[vehiclesSize + 1];
        for (int i = 0; i < vehiclesSize; i++)
        {
            temp[i] = this->vehicle[i];
        }
        temp[vehiclesSize] = newVehicle;
        vehiclesSize++;
        delete[] this->vehicle;
        this->vehicle = temp;
    }

    void removeVehicle(int index)
    {
        if (index < 0 || index >= vehiclesSize)
        {
            cout << "Invalid vehicle index!" << endl;
            return;
        }

        Vehicle **temp = new Vehicle *[vehiclesSize - 1];
        for (int i = 0, j = 0; i < vehiclesSize; i++)
        {
            if (i != index)
            {
                temp[j++] = this->vehicle[i];
            }
        }
        vehiclesSize--;
        delete[] this->vehicle;
        this->vehicle = temp;
    }

    void removeUser(int index)
    {
        if (index < 0 || index >= usersSize)
        {
            cout << "Invalid user index!" << endl;
            return;
        }

        User **temp = new User *[usersSize - 1];
        for (int i = 0, j = 0; i < usersSize; i++)
        {
            if (i != index)
            {
                temp[j++] = this->user[i];
            }
        }
        usersSize--;
        delete[] this->user;
        this->user = temp;
    }

    bool isEligibleForVehicle(int userIndex, int vehicleIndex)
    {
        if (userIndex < 0 || vehicleIndex < 0 || userIndex >= usersSize || vehicleIndex >= vehiclesSize)
        {
            return false;
        }

        string userLicense = ToLower(this->user[userIndex]->getLicenseType());
        string vehicleLicense = ToLower(this->vehicle[vehicleIndex]->getRequiredLicenseType());

        if (userLicense == "learner")
        {
            if (vehicleLicense == "learner")
            {
                return true;
            }
        }
        else if (userLicense == "intermediate")
        {
            if (vehicleLicense == "learner" || vehicleLicense == "intermediate")
            {
                return true;
            }
        }
        else if (userLicense == "full")
        {
            if (vehicleLicense == "learner" || vehicleLicense == "intermediate" || vehicleLicense == "full")
            {
                return true;
            }
        }

        return false;
    }

    RentalSystem(User *Uarray[], int usersSize, Vehicle *Varray[], int vehiclesSize)
    {
        this->usersSize = usersSize;
        this->vehiclesSize = vehiclesSize;
        user = new User *[usersSize];
        vehicle = new Vehicle *[vehiclesSize];
        for (int i = 0; i < usersSize; i++)
        {
            user[i] = Uarray[i];
        }
        for (int i = 0; i < vehiclesSize; i++)
        {
            vehicle[i] = Varray[i];
        }
    }

    ~RentalSystem()
    {
        delete[] user;
        delete[] vehicle;
    }

    void displayAllVehicles()
    {
        for (int i = 0; i < vehiclesSize; i++)
        {
            cout << "Vehicle Index: " << i << endl;
            vehicle[i]->displayVehicleDetails();
            cout << "--------------------" << endl;
        }
    }

    void displayAllUsers()
    {
        for (int i = 0; i < usersSize; i++)
        {
            cout << "User Index: " << i << endl;
            user[i]->displayUserDetails();
            cout << "--------------------" << endl;
        }
    }
    void rentVehicle()
    {
        int userIndex, vehicleIndex;
        displayAllVehicles();
        cout << "\n\n"
             << endl;
        displayAllUsers();
        while (1)
        {

            cout << "Enter the user index: ";
            cin >> userIndex;
            cout << "Enter the vehicle index: ";
            cin >> vehicleIndex;

            if (userIndex >= 0 && vehicleIndex >= 0 && userIndex < usersSize && vehicleIndex < vehiclesSize)
            {
                if (isEligibleForVehicle(userIndex, vehicleIndex))
                {
                    cout << "\n\nRental Successful!" << endl;
                    cout << "\nvehicle Data: \n"
                         << endl;
                    vehicle[vehicleIndex]->displayVehicleDetails();
                    break;
                }
                else
                {
                    cout << "Not eligible for this vehicle!" << endl;
                }
            }
            else
            {
                cout << "Invalid Index!" << endl;
            }
        }
    }
};

int main()
{
    string name;
    double value;
    int age;
    string number;
    string licenseType;
    int noVehicles;

    cout << "Enter number of vehicles: " << endl;
    cin >> noVehicles;
    Vehicle **vehicles = new Vehicle *[noVehicles];
    cout << "\nEnter vehicle details: " << endl;
    for (int i = 0; i < noVehicles; i++)
    {
        vehicles[i] = new Vehicle();
        cout << "Vehicle " << i + 1 << ":\n";
        cout << "Model: ";
        cin >> name;
        vehicles[i]->setModel(name);

        cout << "Rental Price per Day: $";
        cin >> value;
        vehicles[i]->setRentalPrice(value);

        cout << "Required License Type: ";
        cin >> licenseType;
        vehicles[i]->setRequiredLicenseType(licenseType);

        cout << "\n";
    }
    int noUsers;
    cout << "Enter no of Users: " << endl;
    cin >> noUsers;
    User **userArray = new User *[noUsers];
    for (int i = 0; i < noUsers; i++)
    {
        userArray[i] = new User();
        cout << "User " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Contact Number: ";
        cin >> number;

        cout << "License Type: ";
        cin >> licenseType;
        userArray[i]->setDetails(name, age, number, licenseType, i);
    }
    RentalSystem rs(userArray, noUsers, vehicles, noVehicles);
    rs.rentVehicle();

    return 0;
}
