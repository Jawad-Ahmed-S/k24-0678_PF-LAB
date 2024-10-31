#include <stdio.h>
int main()
{
    int rows;

    printf("How many rows?");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = rows; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf(" *");
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = rows; j > i; j--)
        {
            printf(" *");
        }
        printf("\n");
    }

    return 0;
}