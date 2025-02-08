#include<stdio.h>
int main()
{
    struct Address{
        char city[10];
        int zipcode;
    };
    struct Employee{
        int id;
        int salary;
        struct Address A1;
    };

    struct Employee E[2];
    for(int i=0;i<2;i++){
        printf("\n\nEnter Employee Id\n");
        scanf("%d",&E[i].id);
        printf("Enter Employee Salary\n");
        scanf("%d",&E[i].salary);
        printf("Enter Employee city\n");
        scanf("%s", E[i].A1.city);
        printf("Enter Employee zipcode\n");
        scanf("%d", &E[i].A1.zipcode);
    }


    FILE *fptr=fopen("sample.txt","wb+");

    fwrite(E,sizeof(E),2,fptr);
 fclose(fptr);

 FILE *fptrR = fopen("sample.txt","rb");
struct Employee E_read[2];

 
    fread(E_read,sizeof(E),2,fptrR);
    
    for(int i=0;i<2;i++){
        printf("\n\nID : %d",E_read[i].id);
        printf("\nsalary : %d",E_read[i].salary);
        printf("\ncity : %s",E_read[i].A1.city);
        printf("\nzipcode : %d",E_read[i].A1.zipcode);
    }
 return 0;
}