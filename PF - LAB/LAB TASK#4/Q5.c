#include <stdio.h>
int main()
{
    int Amount;
    float discount;
    printf("Enter actual amount :");
    scanf("%d", &Amount);

    if (Amount > 500 && Amount < 2000)
    {
        discount = 5;
    }
    else if (Amount >= 2000 && Amount < 4000)
    {
        discount = 10;
    }
    else if (Amount >= 4000 && Amount <= 6000)
    {
        discount = 20;
    }
    else if (Amount > 6000)
    {
        discount = 35;
    }
    printf("The actual amount = %d \n", Amount);
    printf("The saved amount = %0.0f \n", Amount * (discount / 100));
    printf("The amount after discount= %0.0f", Amount - Amount * (discount / 100));

    return 0;
}