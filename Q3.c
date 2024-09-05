#include<stdio.h>
int main(){
	int salary;
	float taxRate,tax,GrossSalary;
		printf("Enter Your Salary : ");
		scanf("%d",&salary);
		printf("Enter Tax Rate in percent : ");
		scanf("%f",&taxRate);
		
		tax =(salary*(taxRate/100));
		GrossSalary=salary-tax;
		
		printf("You have to pay Rs:%0.0f as tax. \n",tax);
		printf("You will be paid Rs:%0.0f as salary",GrossSalary);
		

}