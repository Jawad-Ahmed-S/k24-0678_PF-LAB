#include<stdio.h>
int main(){
int i, number;
    	printf("Enter a number : ");
    	scanf("%d",&number);
   for(i=2;i<=number;i++){
   		printf("This is a prime number");

	   if(number%i!=0){
		printf("This is a prime number");
   		break;
	   }
		}
		
}
