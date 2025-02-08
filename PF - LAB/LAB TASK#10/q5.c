#include <stdio.h>
void BubbleSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        BubbleSort(arr, n - 1);
    }
}
int main()
{
    int arr[5] = {1, 8, 2, 4, 6};
    BubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}