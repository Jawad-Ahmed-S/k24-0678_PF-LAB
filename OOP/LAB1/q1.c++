#include<iostream>
using namespace std;
int main (){
    int num,isPrime=1;
    cout<<"Enter number";
    cin>>num;
    for(int i=2;i<num/2;i++){
        if(num%i==0){
            isPrime=0;
        }

    }
    if(isPrime)
    {cout<<"Prime";
    }
    else {cout<<"Not Prime";}
    
}
