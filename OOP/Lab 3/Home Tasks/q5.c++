#include <iostream>
using namespace std;
class Calender
{
public:
    int currentYear;
    int monthLimits[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string **month;

    Calender()
    {
        Allocate();
        currentYear = 2025;
    }
    void Allocate()
    {
        month = new string *[12];
        for (int i = 0; i < 12; i++)
        {
            month[i] = new string[monthLimits[i]];
        }
    };

    void AddTask(int date, int monthNo, string task)
    {
        month[monthNo - 1][date - 1] = task;
    }

    void RemoveTask(int date, int monthNo)
    {
        month[monthNo - 1][date - 1] = "";
    }

    void DisplayTasks()
    {
        for (int i = 0; i < 12; i++)
        {
            cout << monthNames[i] << " : " << endl;
            for (int j = 0; j < monthLimits[i]; j++)
            {
                if (month[i][j] != "")
                {
                    cout << j + 1 << " : " << month[i][j] << endl;
                }
            }
        }
    }
};
int main()
{
    Calender cal;
    cal.AddTask(10, 2, "Meeting");
    cal.AddTask(1, 12, "International Trip");
    cal.AddTask(30, 5, "Competitions");
    cal.AddTask(28, 2, "Company's Aniversary");
    cal.AddTask(6, 5, "New Dealers");
    cal.DisplayTasks();
    cal.RemoveTask(6, 5);
    cal.RemoveTask(28, 2);
    cal.DisplayTasks();
}
