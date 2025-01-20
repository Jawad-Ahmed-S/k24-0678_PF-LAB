#include<iostream>
using namespace std;
int main(){
    int num=4;
    int array[4]= {2,7,11,15},target=18;

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
        if((array[i]+array[j])==target){
            cout<<"["<<i<<","<<j<<"]";
            return 0;
        }
        
    }
    }
}