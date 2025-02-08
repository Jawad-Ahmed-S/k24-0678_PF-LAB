#include<stdio.h>
int main(){
int i, number;
    printf("Enter a number : ");
    scanf("%d", &number);
    if(number<2){
        printf("It is a not a prime number");
      
    }else{

    for (i = 2; i < number; i++)
    {

        if (number % i == 0)
        {
            printf("It is not a prime number");
           return 0;
        }
        
    }
    }
    printf("It is prime number");
		
}
