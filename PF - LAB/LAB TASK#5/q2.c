#include <stdio.h>
int main()
{
    char WeekDay,OnVacation;
    printf("Is it a weekday..(y/n)");
    scanf("%c", &WeekDay);
    printf("Are you on vacations..(y/n)");
    scanf(" %c", &OnVacation);

    if (WeekDay == 'n' || WeekDay == 'N' || OnVacation == 'y' || OnVacation == 'Y')
    {
        printf("We Sleep......");
    }
    else
    {
        printf("No Sleeps..");
    }

    return 0;
}