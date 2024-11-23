#include <stdio.h>
const int maxTemp = 30;

int compareTemp()
{
    int temp;
    static int count = 0;
    while (1)
    {
    printf("Enter a temperature:(-1 to stop): ");
    scanf("%d", &temp);


        if (temp == -1)
        {
            break;
        }
        if (temp > maxTemp)
        {
            count++;
        }
}
    return count;
}
int main()
{
    int count = compareTemp();
    printf("Total exceeds this much times %d", count);
    return 0;
}