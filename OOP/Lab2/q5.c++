// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
using namespace std;
void Swap(char *Str,int swaps,int size){
    char temp;
    for(int i=0;i<swaps;i++){
        temp = Str[i];
        Str[i] = Str[size-i-1];
        Str[size-i-1] = temp;
    }
    
}
int main() {
    int StrChar;
    cout<<"enter the number of string characters";
    cin>>StrChar;
    cin.ignore();
    
    char * Str = new char[StrChar+1];
    int swap;
    cout<<"Enter the string";
    cin.getline(Str,StrChar +1);
    int size = strlen(Str);
    cout<<"enter the nuumber of swaps";
    cin>>swap;
    cout<<"\n Original : \n"<<Str<<endl;
    Swap(Str,swap,size);
    cout<<"\n Swapped : \n"<<Str<<endl;
    
    delete[] Str;

    return 0;
}
