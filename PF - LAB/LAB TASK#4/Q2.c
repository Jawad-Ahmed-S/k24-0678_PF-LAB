#include <stdio.h>
int main()
{
    int number;
    printf("Enter a number");
    scanf("%d", &number);

    if (number >= 0 && number % 2 == 0 && number % 10 == 0)
    {
        printf("Thumbs UP!");
    }
    else
    {

        printf("Thumbs Down!");
    }
    return 0;
}