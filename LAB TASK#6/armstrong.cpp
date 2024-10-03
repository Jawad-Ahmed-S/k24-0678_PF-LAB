#include<stdio.h>;
#include<math.h>;
int main(){
	int number,sum=0,result;
	printf("Enter a number :");
	scanf("%d",&number);
	result=number;
	while(result%10!=0){
		sum+= pow(result%10,3);
	result = (result/=10);
	}
	
	if (sum== number){
	printf("It is a Armstrong number \n",sum);
	printf("%d\n\n %d",sum,number);
	}
	

}
