#include <stdio.h>
void Swapped(int *a, int *b, int *c)
{
    int temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}
int main()
{
    int *a;
    int *b;
    int *c;

    int x = 5, y = 6, z = 7;
    a = &x;
    b = &y;
    c = &z;
    printf("\na : %d \nb: %d \nc : %d", *a, *b, *c);
    Swapped(a, b, c);
    printf("\n\n\na : %d \nb: %d \nc : %d", *a, *b, *c);

    return 0;
}