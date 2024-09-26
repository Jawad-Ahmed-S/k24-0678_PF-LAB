#include<stdio.h>
int main(){
    int number;
    printf("Enter a number ..");
    scanf("%d",&number);
    (number%10 == 0)?printf("Last digit zero"):printf("Last digit non zero");
}