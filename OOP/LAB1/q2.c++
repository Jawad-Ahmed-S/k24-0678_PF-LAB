#include<iostream>
using namespace std;
int main(){
    int MarksMaths,MarksEnglish,MarksScience,total;
    float average,percentage;
    struct Students{
        int total;
        float percentage;
        float average;
        struct Marks{
            int MarksEnglish;
            int MarksMaths;
            int MarksScience;
        };
        struct Marks M;
        char grade;
    };
    int nStudents;
cout<<"Number of Sudents";
cin>>nStudents;
struct Students S1[3];
for (int i=0;i<nStudents;i++){

    cout<<"Enter marks of Maths";
    cin>>S1[i].M.MarksMaths;
    cout<<"Enter marks of ENGLISH";
    cin>>S1[i].M.MarksEnglish;
    cout<<"Enter marks of science";
    cin>>S1[i].M.MarksScience;


    S1[i].total = S1[i].M.MarksEnglish+S1[i].M.MarksMaths+S1[i].M.MarksScience;
    S1[i].percentage= ((float)S1[i].total/300)*100;
    S1[i].average=S1[i].total/3;

    if(S1[i].percentage>=90){
        S1[i].grade = 'A';
    }
    else if(S1[i].percentage>=80 && S1[i].percentage<=89){
        S1[i].grade = 'B';
    }
    else if(S1[i].percentage>=70 && S1[i].percentage<=79){
        S1[i].grade = 'C';
    }
    else if(S1[i].percentage>=60 && S1[i].percentage<=69){
        S1[i].grade = 'D';
    }
    else if(S1[i].percentage<60){
        S1[i].grade = 'F';
    }
    
}
for(int i=0;i<nStudents;i++){
    cout<<"total:"<<S1[i].total<<endl;
    cout<<"percentage: "<<S1[i].percentage<<"%"<<endl;
    cout<<"average:"<<S1[i].average<<endl;
    cout<<"Grade: "<<S1[i].grade<<endl;
}
}
