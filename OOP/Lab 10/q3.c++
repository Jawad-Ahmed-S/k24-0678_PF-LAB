#include<iostream>
#include<fstream>
using namespace std;
int main() {

    fstream in1,in2,b1;
    in1.open("ch1.txt",ios::in);
    in2.open("ch2.txt",ios::in);
    b1.open("book.txt",ios::out);
    string temp;
    while(in1>>temp)
    {
        b1<<temp;
    }
    b1<<endl;
    while(in2>>temp)
    {
        b1<<temp;
    }
    in1.close();
    in2.close();
    b1.close();

    b1.open("book.txt",ios::in);
    while(b1>>temp){
        cout<<temp;
    }
    
    return 0;
}