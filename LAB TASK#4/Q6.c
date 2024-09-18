#include <stdio.h>
int main()
{

    int CustomerID, UnitConsumed, AmountCharges, surchargeAmount;
    char Name[10];
    printf("Enter Customer ID :");
    scanf("%d", &CustomerID);
    printf("Enter Unit Consumed :");
    scanf("%d", &UnitConsumed);
    printf("Enter your Name :");
    scanf("                    %c", &Name[10]);

    if (UnitConsumed < 199 && UnitConsumed > 0)
    {
        AmountCharges = UnitConsumed * 16.20;
    }

    else if (UnitConsumed < 300 && UnitConsumed >= 200)
    {
        AmountCharges = UnitConsumed * 20.10;
    }
    else if (UnitConsumed < 400 && UnitConsumed > 500)
    {
        AmountCharges = UnitConsumed * 27.10;
    }
    else if (UnitConsumed >= 500)
    {
        AmountCharges = UnitConsumed * 35.90;
    }
    else
    {
        printf("Invalid range..");
    }
    printf("Customer ID : %d", CustomerID);
    printf("Name : %s", Name);
    printf("Amount Charges : %0.2f", AmountCharges);
    if (AmountCharges > 18000)
    {
        surchargeAmount = (AmountCharges * (15 / 100));
        printf("Surcharge Amount : %0.0f", surchargeAmount);
        printf("Net Payable : %0.0f", surchargeAmount + AmountCharges);
    }

    return 0;
}