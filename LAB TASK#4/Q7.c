#include <stdio.h>
#include <string.h>
int main()
{
    int CustomerID, UnitConsumed;
    char name[10];
    float price, totalPrice=0, surcharge = 0;
    printf("Enter you Customer Id :");
    scanf("%d", &CustomerID);

    printf("Enter you name :");
    scanf("%s", name);
    printf("Enter you Unit Consumed :");
    scanf("%d", &UnitConsumed);
    if (UnitConsumed > 199)
    {
        price = 16.20;
    }
    else if (UnitConsumed <= 200 && UnitConsumed > 300)
    {
        price = 20.10;
    }
    else if (UnitConsumed <= 300 && UnitConsumed > 400)
    {
        price = 27.10;
    }
    else if (UnitConsumed >= 500)
    {
        price = 35.90;
    }
    else
    {
        printf("invalid");
    }
    totalPrice = UnitConsumed * price;

    if (totalPrice > 18000)
    {
        surcharge = totalPrice * (15 / 100);
        totalPrice += surcharge;
    }

    printf("Customer Id: %d \n", CustomerID);
    printf("Customer Name : %s \n", name);
    printf("Units Consumed : %d \n", UnitConsumed);
    printf("Amount Charges @%0.2f per unit : %0.2f\n", price, totalPrice);
    printf("Surcharge Amount : %0.2f \n", surcharge);
    printf("Net paid by the Customer%0.2f :", totalPrice);
    return 0;
}