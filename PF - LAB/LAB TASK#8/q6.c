#include <stdio.h>
int main()
{
    // int coficient = 1;

    int arr[6][6] = {0};
    for (int i = 0; i < 6; i++)
    {

        arr[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int n = 6; n > i; n--)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
