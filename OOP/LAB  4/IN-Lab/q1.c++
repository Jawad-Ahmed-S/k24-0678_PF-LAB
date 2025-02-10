#include<iostream>
using namespace std;
class Student{
        int StudentId;
        string name;
        int age;        
        char grade;
        public:
        Student(){
            grade = 'N';
        }
        Student(int studentid,string name,int age,char grade){
            this->StudentId = studentid;
            this->age = age;
            this->name = name;
            this->grade = grade;
        }
        void promoteStudent(char grade){
            this->grade = grade;
        }
        bool isEligibleForScholarship(){

            cout<<"\n"<<(grade=='A')?true:false;
            return (grade=='A')?true:false;
        }
        void displayDetails(){
            cout<<"\n\n\n\nStudent Name : "<<name;
            cout<<"\nStudent StudentId : "<<StudentId;
            cout<<"\nStudent Age : "<<age;
            cout<<"\nStudent Grade : "<<grade;
        }
};
int main(){

Student S(123,"Jawad",18,'B');
Student S1(783,"Ibrahim",17,'A');
Student S2(546,"obaid",20,'A');
S1.displayDetails();
S1.promoteStudent('B');
S1.displayDetails();

S2.isEligibleForScholarship();
S.displayDetails();

    


return 0;
}