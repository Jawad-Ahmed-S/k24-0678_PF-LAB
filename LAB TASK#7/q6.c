#include <stdio.h>
int main()
{
    int arr[] = {1, 3, 4, 5};
    int count[100] = {0};
    for (int i = 0; i < 4; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] > 1)
        {
            printf("number %d occurs more than once", arr[i]);
            return 0;
        }
    }
    printf("no duplicates");
    return 0;
}