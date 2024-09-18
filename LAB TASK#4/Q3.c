#include <stdio.h>
int main()
{
    char operator;
    int num1, num2;
    printf("Enter a number");
    scanf("%d", &num1);
    printf("Enter a number");
    scanf("%d", &num2);
    printf("Enter a operator");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        printf("The addition of two gives :%d", num1 + num2);
        break;

    case '-':
        printf("The Subtraction of two gives :%d", num1 - num2);
        break;

    case '*':
        printf("The Multiplication of two gives :%d", num1 * num2);
        break;

    case '/':
        printf("The Division of two gives :%d", num1 / num2);
        break;

    default:
        printf("Invalid operator");
        break;
    }

    return 0;
}