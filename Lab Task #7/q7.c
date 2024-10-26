#include <stdio.h>
int main()
{
    int num1 = 0, num2 = 0, temp = 0, i = 0;
    char str[10] = "20+30-45-1";
    char operator = '+';
    while (str[i] != '\0')
    {

        while (str[i] >= '0' && str[i] <= '9')
        {
            temp = str[i] - '0';
            num2 = num2 * 10 + temp;
            i++;
        }

        if (operator == '+')
        {
            num1 = num1 + num2;
        }
        else if (operator == '-')
        {
            num1 = num1 - num2;
        }
        else
        {
            printf("Invalid operator \n");
            break;
        }
        operator =str[i];
        num2 = 0;
        i++;
    }
    printf("The sum is : %d", num1);

    return 0;
}