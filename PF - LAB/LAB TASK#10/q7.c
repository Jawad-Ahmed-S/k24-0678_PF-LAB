#include <stdio.h>
struct Date
{
    int Day;
    int Month;
    int Year;
};
int days(struct Date D1[2])
{
    int year_Days = (D1[0].Year - D1[1].Year) * 365;

    int Month_Days;
    int MonthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (D1[0].Month > D1[1].Month)
    {

        for (int i = D1[0].Month; i < D1[1].Month; i++)
        {
            Month_Days += MonthLength[i];
        }
    }

    else if (D1[1].Month > D1[0].Month)
    {
        for (int i = D1[1].Month; i < D1[0].Month; i++)
        {
            Month_Days += MonthLength[i];
        }
    }
    else
    {
    }
    int Day_days = D1[1].Day + (MonthLength[D1[0].Month] - D1[0].Day);

    return (Day_days);
}
int DayWeek(struct Date D1)
{
    int WeekDay = D1.Day + (D1.Month * 12) + (D1.Year * 365.25);
    return (WeekDay % 7);
}
int main()
{
    struct Date D1 =
        {8, 11, 2024};
    //     {1, 12, 2024}};
    // int day13 = days(D1);
    char Days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    printf("Days : %s", Days[DayWeek(D1)]);

    // printf("Days : %d", day13);
    return 0;
}