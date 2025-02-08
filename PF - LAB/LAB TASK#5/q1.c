#include <stdio.h>
int main()
{
    float noOfCalories, FatGrams;
    float FatPercent, FatCalories;

    printf("Enter no of calories");
    scanf("%f", &noOfCalories);

    printf("Enter fat Grams");
    scanf("%f", &FatGrams);
    if (noOfCalories <= 0 || FatGrams < 0)
    {
        printf("errorr: invalid inputs");
        return 0;
    }

    FatCalories = FatGrams * 9;
    if (noOfCalories < FatCalories)
    {
        printf("errorr: invalid inputs");
        return 0;
    }
    FatPercent = (FatCalories / noOfCalories) * 100;
    printf("Fat Percent  =  %.2f", FatPercent);
    return 0;
}
