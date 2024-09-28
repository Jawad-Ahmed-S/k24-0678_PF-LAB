#include <stdio.h>
int main()
{
    char coffeeType, size;
    float water, sugar, mix, coffee, milk, time;
    float msize;
    printf("Which type of coffee you want? (black - b/white - w)");
    scanf("%c", &coffeeType);
    printf("Which size of coffee you want? (original - o/Double - d/manual - m)");
    scanf(" %c", &size);

    switch (size)
    {
    case 'o':
        time = 1;
        break;
    case 'd':
        time = 1.5;
        break;
    case 'm':
        printf("How much percent of the cup you want additional (in percent)");
        scanf("%f", &msize);
        time = 1 + (msize / 100);
        break;
    default:
        printf("Invalid size.");
    }
    
    switch (coffeeType)
    {
    case 'w':
    case 'W':
        water = (15 * time);
        sugar = (15 * time);
        mix = 20 * time;
        coffee = 2 * time;
        milk = 4 * time;
        printf("Coffee : White \n");
        printf("Water = %.0f mins \n", water);
        printf("Sugar = %.0f mins \n", sugar);
        printf("Mix = %.0f mins \n", mix);
        printf("Coffee = %.0f mins \n", coffee);
        printf("Milk = %.0f mins \n", milk);
        printf("Mix = %.0f mins \n", mix);
        break;
    case 'b':
    case 'B':

        water = 20 * time;
        sugar = 20 * time;
        mix = 25 * time;
        coffee = 15 * time;

        printf("Coffee : Black \n");
        printf("Water = %.0f mins \n", water);
        printf("Sugar = %.0f mins \n", sugar);
        printf("Mix = %.0f mins \n", mix);
        printf("Coffee = %.0f mins \n", coffee);
        printf("Mix = %.0f mins \n", mix);
        break;
    default:
        printf("invalid type..");
    }
    return 0;
}