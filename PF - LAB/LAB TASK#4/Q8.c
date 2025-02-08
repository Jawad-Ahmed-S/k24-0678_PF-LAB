#include<stdio.h>
int main(){
    int number;
    printf("Enter a number  : ");
    scanf("%d",&number);

    if(1<=number && number<=9){
        if(number==1){
            printf("one");
        }
        
        if(number==2){
            printf("two");
        }
        
        if(number==3){
            printf("three");
        }
        
        if(number==4){
            printf("four");
        }
        
        if(number==5){
            printf("five");
        }
        
        if(number==6){
            printf("six");
        }
        
        if(number==7){
            printf("seven");
        }
        
        if(number==8){
            printf("eight");
        }
        if(number==9){
            printf("nine");
        }
    }
    else if(number>9){
            printf("Greater than nine");
        }
    else{
        printf("Invalid number..");
    }

}