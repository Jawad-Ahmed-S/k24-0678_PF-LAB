#include<stdio.h>
int main()
{
    struct Company{
        char feildName[10];
        char date[10];
        char department[5][10];
    };
        struct Company C={"IT","1/2/2024",{"CS","SE","AI","ABC","BAC"}};
   
    printf("Comapny Name : %s\n",C.feildName);
    printf("Comapny Name : %s\n",C.date);
    for(int i=0;i<5;i++){
        printf("\t%s",C.department[i]);
    }
 return 0;
}