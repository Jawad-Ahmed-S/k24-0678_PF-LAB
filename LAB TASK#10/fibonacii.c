#include <stdio.h>
int fabo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        return fabo(n - 1) + fabo(n - 2);
    }
}
int main()
{
    int i;
    printf("Enter a number");
    scanf("%d", &i);
    // fabo(i);
    printf("%d", fabo(i));
    return 0;
}