#include<stdio.h>
int main()
{
    struct Student{
        int rollNo;
        struct marks{
            int maths;
            int science;
            int english;
        };
        struct marks m;
    };
    struct Student S[5];

    for(int i=0;i<5;i++){
        printf("Enter Student %d RollNo:\n",i+1);

        scanf("%d", &S[i].rollNo);
        printf("Enter Student Marks for Maths:\n");
        scanf("%d", &S[i].m.maths);
        printf("Enter Student Marks for Science:\n");
        scanf("%d", &S[i].m.science);

        printf("Enter Student Marks for English:\n");
        scanf("%d", &S[i].m.english);
    }

    for(int i=0;i<5;i++){
        printf("\nThe average of Student %d : %d", i+1,(S[i].m.english + S[i].m.maths + S[i].m.science) / (3));
    }
 
 return 0;
}