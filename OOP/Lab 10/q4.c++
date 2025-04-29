#include<iostream>
#include<fstream>
using namespace std;
int main() {

    fstream file;
    file.open("info.txt",ios::out);
    file<<"C++ is a powerful programming language.";
    file.close();
    file.open("info.txt",ios::in | ios::out);
    cout<<"Current position of Put Pointer: "<<file.tellp()<<endl;
    cout<<"Current position of Get Pointer: "<<file.tellg()<<endl;
    file.seekg(9);
    file.seekp(9);
    file<<"dynamic";
    cout<<"Current position of Put Pointer: "<<file.tellp()<<endl;
    cout<<"Current position of Get Pointer: "<<file.tellg()<<endl;
    file.seekg(0);
    file.seekp(0);
    string temp;
    while(file>>temp){
    cout<<temp<<" ";
    }

    return 0;
}