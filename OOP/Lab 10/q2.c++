#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    fstream file;
    string name;
    string email;
    int Experience;
    string summary;

cout<<"OLD DATA:";

    file.open("Resume.txt",ios::out);
    cout<<"Enter Name : \n";
    cin>>name;
    cout<<"Enter email : \n";
    cin>>email;
    cout<<"Enter experience : \n";
    cin>>Experience;
    cout<<"Enter summary : \n";
    cin>>summary;

    file<<name<<"\n"<<email<<"\n"<<Experience<<"\n"<<summary;

    file.close();
    
cout<<"NEW DATA:";
    file.open("Resume.txt",ios::trunc);
    cout<<"Enter Name : \n";
    cin>>name;
    cout<<"Enter email : \n";
    cin>>email;
    cout<<"Enter experience : \n";
    cin>>Experience;
    cout<<"Enter summary : \n";
    cin>>summary;


    file<<name<<"\n"<<email<<"\n"<<Experience<<"\n"<<summary;
    file.close();

    file.open("Resume.txt",ios::in);
string line;

    while(!file.eof())
    getline(file,line);
    cout<<line;

    file.close();

    
}