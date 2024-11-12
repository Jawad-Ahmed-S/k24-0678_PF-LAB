#include <stdio.h>
int main()
{
    void SwapIntegers(int *num1, int *num2);
    int *num1, *num2;
    int a, b;
    printf("Enter a");
    scanf("%d",&a);
    printf("Enter b");
    scanf("%d",&b);
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