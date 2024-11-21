#include<stdio.h>
int main(){
    FILE *fptr =fopen("q1data1.txt","r");
    char arr[100];
    fscanf(fptr,"%s",arr);
	fclose(fptr);
    printf("%s",arr);
    
    
    FILE *fptr1 =fopen("q1data2.txt","w");
    fprintf(fptr1,arr);
	fclose(fptr1);
    
}

