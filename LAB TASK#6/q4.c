#include <stdio.h>
int main()
{
    int i, number, isPrime, var1, var2;
    printf("Enter a number : ");
    scanf("%d", &number);
    if (number < 2)
    {
        isPrime = 0;
    }
    else
    {

        for (i = 2; i < number; i++)
        {

            if (number % i == 0)
            {
                isPrime = 0;
                return 0;
            }
        }
    }
    isPrime = 1;

    if (isPrime)
    {
        printf("0 1");
        var1 = 0;
        var2 = 1;
        for (i = 0; i < number; i++)
        {
            var1 = var1 + var2;
            var2 = var1 + var2;
            if (var2 >= number && var1<=number)
            {
                printf(" %d",var1);
                break;
            }
            else if (var1 >= number)
            {
                break;
            }
            printf(" %d %d", var1, var2);
        }
    }
}