#include<stdio.h>
int main(){
    FILE *fptr =fopen("q1data.txt","r");
    char arr[100];
    fscanf(fptr,"%s",arr);

    printf("%s",arr);
}