#include <stdio.h>
int main()
{
    struct Package
    {
        char name[10];
        char destination[10];
        int duration;
        int cost;
        int noOfSeats;
    };

    struct Package P[3] = {
        {"Package 1", "USA", 3, 250000, 2},
        {"Package 2", "UK", 5, 55000, 2},
        {"Package 3", "UAE", 2, 750000, 2},
    };
    int no;
    printf("Enter Which Package You Want? (1-2-3)");
    scanf("%d", &no);
    if (no == 1)
    {
        P[0].noOfSeats -= 1;
        printf("Package %d booked.", no);
    }
    else if (no == 2)
    {
        P[1].noOfSeats -= 1;
        printf("Package %d booked.", no);
    }
    else if (no == 3)
    {
        P[2].noOfSeats -= 1;
        printf("Package %d booked.", no);
    }
    else
    {
        printf("invalid");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\nName : %s\n", P[i].name);
        printf("Destination : %s\n", P[i].destination);
        printf("Duration : %d\n", P[i].duration);
        printf("Cost : %d\n", P[i].cost);
        printf("No Of Seats : %d\n", P[i].noOfSeats);
        return 0;
    }
}