#include <stdio.h>
int main()
{
    int multiple3;
    printf("Enter a number");
    scanf("%d", &multiple3);

    if (multiple3 % 3 == 0)
    {
        printf("This number is a multiple of 3");
    }
    else
    {
        printf("This number is not a multiple of 3");
    }
    return 0;
}