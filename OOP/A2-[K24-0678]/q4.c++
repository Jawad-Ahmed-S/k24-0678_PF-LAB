#include <iostream>
using namespace std;
string generateHash(string pass)
{
    long hash = 5381;
    int passLength = pass.length();
    for (int i = 0; i < passLength; i++)
    {
        hash = hash * 33 + pass[i];
    }
    return to_string(hash);
}
class User
{
protected:
    int id;
    string name;
    string email;
    string hashed_password;
    string *PermissionList;
    int permissions;

public:
    User(int id, string name, string email, string hashed_password, string *permissionList, int permissions)
    {
        this->id = id;
        this->name = name;
        this->email = email;
        this->hashed_password = hashed_password;
        this->permissions = permissions;
        this->PermissionList = permissionList;
    }
    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Hashed Password: " << hashed_password << endl;
        cout << "Permission List: ";
        for (int i = 0; i < 5; i++)
        {
            cout << PermissionList[i] << " ";
        }
        cout << endl;
    }
    void hasPermission(string action)
    {
        for (int i = 0; i < permissions; i++)
        {
            if (PermissionList[i] == action)
            {
                cout << "User has permission to perform " << action << endl;
                return;
            }
        }
    }
};
class Student : public User
{
protected:
    string *assignment;
    int assignments;

public:
    Student(int id, string name, string email, string pass, string *permList, int nPerm, string *assignment, int nAssignment) : User(id, name, email, pass, permList, nPerm)
    {
        this->assignments = nAssignment;
        this->assignment = new string[nAssignment];
        for (int i = 0; i < nAssignment; i++)
        {
            this->assignment[i] = assignment[i];
        }
    }
    void submitAssignment(int i)
    {
        assignment[i] = "Submitted";
        cout << "Assignment " << i + 1 << " submitted successfully" << endl;
    }
    void display() override
    {

        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < assignments; i++)
        {
            cout << assignment[i] << " ";
        }
        cout << endl;
    }
};
class TA : public Student
{
    string project[2];
    Student **students;
    int nStudents;

public:
    TA(int id, string name, string email, string pass, string *permList, int nPerm, string *assignment, int nAssignment) : Student(id, name, email, pass, permList, nPerm, assignment, nAssignment)
    {
        this->nStudents = 0;
        this->students = new Student *[10];
        // delete[] PermissionList;
    }
    void setProject(string ProjectName, int i)
    {
        if (i < 2)
            project[i] = ProjectName;
    }
    string getProject()
    {
        return project[0] + " and " + project[1];
    }
    void addStudent(Student *s)
    {
        if (nStudents < 10)
        {
            students[nStudents] = s;
            nStudents++;
        }
        else
        {
            cout << "Cannot add more students" << endl;
        }
    }
    void veiwStudents()
    {
        cout << "Students: " << endl;
        for (int i = 0; i < nStudents; i++)
        {
            students[i]->display();
            cout << endl;
        }
    }
};

class Teacher : public User
{
protected:
    string *projects;
    int assignedProjects;

public:
    Teacher(int id, string name, string email, string pass, string *permList, int nPerm) : User(id, name, email, pass, permList, nPerm)
    {
        projects = new string[2];

        this->assignedProjects = 0;
    }
    void display() override
    {
        User::display();
        cout << "Role: Professor" << endl;
    }
    void assignProject(TA *t, string ProjectName)
    {
        t->setProject(ProjectName, 1);
        cout << "Project Assigned Successfully" << endl;
    }
    void viewAllProject(TA **t, int nTA)
    {
        for (int i = 0; i < nTA; i++)
        {
            // for(int j=0;j<2;j++){
            cout << "Project Name: " << t[i]->getProject() << endl;
            // }
        }
    }
};

int main()
{
    // Permissions
    string pStudent[1] = {"submit"};
    string pTA[2] = {"View Assignments", "Manage Students"};
    string pTeacher[3] = {"View Assignments", "Manage Students", "Create Projects"};

    // Projects
    string projects1[1] = {"Project 2"};
    string projects2[2] = {"Project 3", "Project 4"};

    // Creating Student Objects
    Student *s1 = new Student(3, "Alice Johnson", "alicejohnson@example.com", generateHash("qwerty456"), pStudent, 1, projects1, 1);
    Student *s2 = new Student(4, "Bob Brown", "bobbrown@example.com", generateHash("asdfghjkl"), pStudent, 1, projects1, 1);

    // Creating TA Object
    TA *t1 = new TA(5, "Tom Smith", "tomsmith@example.com", generateHash("123456789"), pTA, 2, projects2, 2);

    // Creating Teacher Object
    Teacher *t2 = new Teacher(6, "Alice Johnson", "alicejohnson@example.com", generateHash("qwerty456"), pTeacher, 3);

    // Assign Project to TA
    t2->assignProject(t1, "Project 3");

    // View All Projects assigned to TA
    t2->viewAllProject(&t1, 1);

    // Submitting Assignments
    s1->submitAssignment(0);
    s2->submitAssignment(0); // Fixed to 0 to avoid out-of-bound error.

    // Displaying Information
    cout << "\nDisplaying Student Information:\n";
    s1->display();
    cout << "\nDisplaying Student Information:\n";
    s2->display();

    // Displaying TA Information
    cout << "\nDisplaying TA Information:\n";
    t1->display();

    // Adding a student to TA's list
    t1->addStudent(s1);
    t1->addStudent(s2);

    // Viewing Students under TA
    t1->veiwStudents();

    return 0;
}
