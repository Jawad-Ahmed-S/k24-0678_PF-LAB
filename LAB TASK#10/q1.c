#include<stdio.h>
void sum(int arr[5],int length){
    if(length== 0)
    return;
    else{
            printf("%d",arr[0]);
            sum(arr+1,length-1);
    }
}

int main()
{
     int arr[5]={1,2,3,4,5};
    sum(arr,5);
 
 return 0;
}