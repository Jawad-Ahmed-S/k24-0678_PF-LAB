#include <stdio.h>
int main()
{
    struct Date
    {
        int day;
        int month;
        int Year;
    };
    struct Event
    {
        char eventName[30];
        struct Date D;
        char location[10];
    };

    struct Event E = {
        "Hasna Zaroori Nahi", {11, 28, 2024}, "Auditorium"};

    printf("Event : %s\n", E.eventName);
    printf("Dated on : %d-%d-%d\n", E.D.day, E.D.month, E.D.Year);
    printf("Event : %s\n", E.location);

    return 0;
}