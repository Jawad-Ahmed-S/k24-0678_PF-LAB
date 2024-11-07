#include <stdio.h>
int main()
{
    void SwapIntegers(int *num1, int *num2);
    int *num1, *num2;
    int a = 2, b = 3;
    num1 = &a;
    num2 = &b;
    SwapIntegers(num1, num2);
    printf("%d    %d", *num1, *num2);

    return 0;
}
void SwapIntegers(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}