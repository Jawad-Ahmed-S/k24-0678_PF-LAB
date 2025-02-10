// You are building an employee management system. Create a class `Employee` to manage employee
// records.
// Requirements:
// 1. Attributes:
//  `employeeID` (int)
//  `name` (string)
//  `department` (string)
//  `salary` (double)
// 2. Define a default constructor that initializes `salary` to `0.0`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
//  `isManager()`: Returns `true` if the employee's department is "Management".
//  `displayDetails()`: Displays the employee's details.
// 5. Create a few `Employee` objects and test the methods.
#include<iostream>
using namespace std;
class Employee{
    int employeeID;
    string name;
    string department;
    double salary;
    public:
    Employee(){
        salary = 0.0;
    }
    Employee(int id, string name, string depart, double salary){
    this->employeeID = id;
    this->name = name;
    this->department = depart;
    this->salary = salary;
    }
    void giveBonus(double amount){
        if(amount>0){
        salary += amount;
        cout<<"Bonus amount: "<<amount<<" added."<<endl;
        } 
        else{
            cout<<"\nInvalid bonus amount!"<<endl;
        }
    }
    bool isManager(){
        return department == "Management"? true : false;
    }
    void displayDetails(){
        cout<<"\nEmployee ID: "<<employeeID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
int main(){

    Employee e1(1, "Jahanzaib", "Marketing", 50000);
    Employee e2(2,"Ali Khan","Development",60000);

    e1.displayDetails();
    cout<<"Is Manager?"<<(e2.isManager()? "Yes" : "No")<<endl;
    e1.giveBonus(10000);
    e1.displayDetails();
    
    e2.giveBonus(20000);
    e2.displayDetails();


return 0;
}