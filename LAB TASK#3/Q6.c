#include <stdio.h>
int main()
{
    float y1, y2, x1, x2, slope;
    printf("Enter value of y1");
    scanf("%f", &y1);
    printf("Enter value of y2");
    scanf("%f", &y2);
    printf("Enter value of x1");
    scanf("%f", &x1);
    printf("Enter value of x2");
    scanf("%f", &x2);

    slope = (y2 - y1) / (x2 - x1);

    printf("Slope = %0.3f", slope);
    return 0;
}
