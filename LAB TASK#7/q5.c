#include <stdio.h>
int main()
{
    int arr[10] = {1, 2, 2, 3, 3, 3, 3, 3, 4, 2};
    int count[10] = {0};
    int counter;

    for (int i = 0; i < 10; i++)
    {
        counter = 1;
        if (count[i] < 0)
        {
            continue;
        }
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                counter++;
                count[j]=-1;
            }
        }
        count[i] = counter;
    }
    for (int i = 0; i < 10; i++)
    {
        if(count[i]>0)
        printf("%d", count[i]);
    }
    return 0;
}