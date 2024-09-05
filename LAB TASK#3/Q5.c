#include <stdio.h>
int main()
{
    float Principle, InterestRate, Timeperiod, InterestAmount;
    printf("Enter a Principle Amount(100-1000000)Rs. : ");
    scanf("%f", &Principle);
    printf("Enter rate of interest '(5 - 10)%' : ");
    scanf("%f", &InterestRate);
    printf("Enter Time period  :(1-10)Years ");
    scanf("%f", &Timeperiod);

    if (Principle < 100 || Principle > 1000000)
    {
        printf("invalid principle");
    }
    else
    {
        if (InterestRate < 5 || InterestRate > 10)
        {
            printf("invalid Interest Rate");
        }
        else
        {
            if (Timeperiod < 1 || Timeperiod > 10)
            {
                printf("invalid Time Period");
            }
            else
            {
                InterestAmount = Principle * (InterestRate / 100);
                printf("Interest Amount on this %0.1f Principle = %0.1f", Principle, InterestAmount);
            }
        }
    }
    return 0;
}