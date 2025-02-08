#include <stdio.h>
#include <math.h>
int main()
{
    int number, sum = 0, result, digit;
    printf("Enter a number :");
    scanf("%d", &number);
    result = number;
    while (result > 0)
    {
        digit = result % 10;
        sum += (digit * digit * digit);
        result /= 10;
    }

    if (sum == number)
    {
        printf("It is an Armstrong number \n");
    }
    else
    {
        printf("It is not an Armstrong number \n");
    }
}