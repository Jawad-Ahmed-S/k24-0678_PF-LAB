#include<stdio.h>
int main(){
	int a,b,c;
	printf("Enter a number : ");
	scanf("%d",&a);
	printf("Enter a number : ");
	scanf("%d",&b);
	
	
	c=a;
	a=b;
	b=c;
	
	
	printf("The value of a: %d  \nThe value of b: %d",a,b);
}