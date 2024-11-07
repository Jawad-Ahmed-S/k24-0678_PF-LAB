#include <stdio.h>
int main()
{
    int n = 3;
    int arr[2][3][2] = {0};
    int num;
    scanf("%d", &num);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            if (num % 2 == 0)
            {
                arr[0][i][j] = num;
                num--;
            }
            if ((num % 2 != 0))
            {
                arr[1][i][j] = num;
                num--;
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        printf("%s \n", (i == 0) ? "even" : "odd");
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {

                printf("%d \t", arr[i][j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}