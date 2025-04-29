#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student{
    int id;
    string name;
    float gpa;
    fstream output;
    string fileName;
    Student(string name = "Student.txt"):fileName(name){
            output.open(fileName,ios::app);
            if(!output){
                cerr<<"Error: Opening";
            }
    }
    void openfileRead(){
        output.open(fileName,ios::in);
            if(!output){
                cerr<<"Error: Opening";
            }
    }
    void writeData(string data){
        if(output.is_open()){
            output<<data<<" ";
        }
    }
    void writeData(int data){
        if(output.is_open()){
            output<<data<<" ";
        }
    }
    void writeData(float data){
        if(output.is_open()){
            output<<data<<" ";
        }
    }
    void closeFile(){
        if(output.is_open()){
            output.close();
            cout<<"File closed";

        }
        else{
            cout<<"Already closed";
        }

    }
    void readData(){
        while(!output.eof()){
            
        string line;
        getline(output,line);
        cout<<line<<"\n";
        }
    }
    void inputData(){
        cout<<"Enter Id : ";
        cin>>id;        
        writeData(id);
        cout<<"Enter Name : ";        
        cin>>name;    
        writeData(name);    
        cout<<"Enter GPA : ";        
        cin>>gpa;
        writeData(gpa);
        output<<"\n";    
    }
};
int main(){
    Student s[2];

for(int i=0;i<2;i++){
s[i].inputData();
}
s->closeFile();
s->openfileRead();
        cout<<"\nId   |  Name  |  GPA \n";
for(int i=0;i<2;i++){
    s[i].readData();
}
s->closeFile();
}
