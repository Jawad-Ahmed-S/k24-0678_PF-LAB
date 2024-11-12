#include <stdio.h>
float operation(float a, float b, char operator);
int main()
{
    float a, b;
    char op;
    printf("Enter a :");
    scanf("%f", &a);
    printf("Enter b :");
    scanf("%f", &b);
    printf("Enter operator :");
    scanf(" %c", &op);

    float result = operation(a, b, op);
    printf("Results: %0.1f", result);

    return 0;
}
float operation(float a, float b, char operator)
{
    switch (operator)
    {
    case '+':
        return a + b;
        break;

    case '-':
        return a - b;
        break;

    case '*':
        return a * b;
        break;

    case '/':
        return a / b;
        break;

    case '%':
        return ((int)a % (int)b);
        break;

    default:
        break;
    }
}