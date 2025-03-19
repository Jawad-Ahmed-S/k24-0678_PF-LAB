#include <iostream>
using namespace std;

class Course; // Forward declaration to fix circular dependency

class Person
{
protected:
    string name;
    int id;
    string address;
    string contact;
    string email;

public:
    Person() : name(""), id(0), address(""), contact(""), email("") {}

    Person(string name, int id, string address, string contact, string email = "")
        : name(name), id(id), address(address), contact(contact), email(email) {}

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
        cout << "Email: " << email << endl;
    }

    // Getter functions for protected members
    string getName() { return name; }
    int getId() { return id; }
};

class Student : public Person
{
    float GPA;
    string EnrollmentYear;
    int NoCourses;
    Course *course; // Pointer to Course to fix circular dependency

public:
    Student() : GPA(0.0), EnrollmentYear(""), NoCourses(0), course(nullptr) {}

    Student(string name, int id, string address, string contact, float GPA, string EnrollmentYear, int noCourses)
        : Person(name, id, address, contact), GPA(GPA), EnrollmentYear(EnrollmentYear), NoCourses(noCourses), course(nullptr) {}

    void displayInfo()
    {
        Person::displayInfo();
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << EnrollmentYear << endl;
        cout << "Number of Courses: " << NoCourses << endl;
    }
};

class Professor : public Person
{
    string department;
    int noCourses;
    int salary;

public:
    Professor() : department(""), noCourses(0), salary(0) {}

    Professor(string name, int id, string address, string contact, string department, int noCourses, int salary)
        : Person(name, id, address, contact), department(department), noCourses(noCourses), salary(salary) {}

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Number of Courses: " << noCourses << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person
{
    string position;
    int salary;
    string department;

public:
    Staff(string name, int id, string address, string contact, string position, int salary, string department)
        : Person(name, id, address, contact), position(position), salary(salary), department(department) {}

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};

class Course
{
    string courseName;
    int creditHours;
    float schedule;
    int courseId;
    int noStudent;
    Student *students;
    Professor *professor;

public:
    Course() : courseName(""), creditHours(0), schedule(0.0), courseId(0), noStudent(0), students(nullptr), professor(nullptr) {}

    Course(string courseName, int creditHours, float schedule, int courseId, Professor *professor)
        : courseName(courseName), creditHours(creditHours), schedule(schedule), courseId(courseId), noStudent(0), professor(professor)
    {
        students = new Student[100]; // Allocating space for up to 100 students
    }

    void registerStudent(Student s1)
    {
        if (noStudent < 100)
        {
            students[noStudent] = s1;
            noStudent++;
        }
        else
        {
            cout << "Course is full, cannot register more students!" << endl;
        }
    }

    void displayCourseInfo()
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Credit Hours: " << creditHours << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Course ID: " << courseId << endl;
    }

    ~Course()
    {
        delete[] students;
    }
};

int main()
{
    // Example Usage:
    Professor prof("Dr. Smith", 101, "123 Main St", "555-1234", "Computer Science", 3, 75000);
    Course c("OOP", 3, 9.30, 1101, &prof);

    Student s1("John Doe", 201, "456 Elm St", "555-5678", 3.8, "2024", 5);
    c.registerStudent(s1);

    cout << "Professor Info:" << endl;
    prof.displayInfo();
    cout << "\nCourse Info:" << endl;
    c.displayCourseInfo();
    cout << "\nStudent Info:" << endl;
    s1.displayInfo();

    return 0;
}
