#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nElement;
     printf("Enter the number of element you want to include in the array ");
     scanf("%d",&nElement);
 
    int *array = (int *)calloc(nElement,sizeof(int));
    int sum=0;
    for(int i=0;i<nElement;i++){
        printf("Enter the element");
        scanf("%d",&array[i]);
        sum+=array[i];
    }
    printf("Sum = %d",sum);
 return 0;
}