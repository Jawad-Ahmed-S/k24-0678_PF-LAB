#include <stdio.h>
int main()
{
    int arr[6];
    int temp = 0;
    for (int i = 0; i < 6; i++)
    {
        printf("Enter a number");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
    }
    for (int i; i < 6; i++)
    {
        printf("%d , ", arr[i]);
    }
    return 0; // 486236
}