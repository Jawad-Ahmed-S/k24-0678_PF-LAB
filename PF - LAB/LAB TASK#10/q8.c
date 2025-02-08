#include<stdio.h>
int linearSearch(int arr[],int length,int target,int current){
    if((arr[current]==target)  ||current>length ){
        return 0;
    }
    else{
        linearSearch(arr,length,target,current+1);
    }
}
int main()
{
    int length=5;
    int arr[5]={1,2,3,4,5};
    int target=5;
    int current=0;
    int Found=linearSearch(arr,length,target,current);

    printf("%s...%d",(Found==0)?"Found":"Not Found",target);

 return 0;
}