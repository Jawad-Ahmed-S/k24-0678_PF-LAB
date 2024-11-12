#include <stdio.h>
#include <string.h>
void Sort(char arr[999][10], int n);
int main()
{
    int n;
    printf("Enter no of strings : ");
    scanf("%d", &n);
    char arr[999][10];
    for (int i = 0; i < n; i++)
    {
        printf("Enter a string : ");
        scanf("%s", arr[i]);
    }
    Sort(arr, n);
    for (int i = 0; i < n; i++)
    {

        printf("%s\n", arr[i]);
    }

    return 0;
}
void Sort(char arr[999][10], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                char temp[10];

                strcpy(temp, arr[j + 1]);
                strcpy(arr[j + 1], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}