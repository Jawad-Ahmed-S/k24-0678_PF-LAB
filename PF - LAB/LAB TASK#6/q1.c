#include<stdio.h>
int main(){
	int number,sum=0;
    while(number!=0){
    	printf("Enter a number : ");
    	scanf("%d",&number);
    	sum+=number;
	}
	printf("Sum = %d",sum);
}
