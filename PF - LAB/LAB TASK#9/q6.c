#include <stdio.h>

void max_min(int arr[6], int *ptrMax, int *ptrMin);
int main()
{
    int Max, Min;
    int arr[6] = {45, 78, 2, 3, 6, 41};
    max_min(arr, &Max, &Min);
    printf("Maximum : %d\n", Max);
    printf("Minimum : %d", Min);

    return 0;
}
void max_min(int arr[6], int *ptrMax, int *ptrMin)
{

    *ptrMax = arr[0];
    *ptrMin = arr[0];
    int length = 6;
    for (int i = 0; i < length; i++)
    {
        if (*ptrMax < arr[i])
        {
            *ptrMax = arr[i];
        }
        if (*ptrMin > arr[i])
        {
            *ptrMin = arr[i];
        }
    }
}