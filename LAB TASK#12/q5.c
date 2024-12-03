#include <stdio.h>
#include <stdlib.h>
int main()
{
    int nElement;
    int nidElement;
    printf("Enter the number of element you want to include in the array :");
    scanf("%d", &nElement);

    char *array = (char *)calloc(nElement, sizeof(char));
    char *id = (char *)calloc(nidElement, sizeof(char));
    printf("Enter your name :");
    while (getchar() != '\n')
        ;
    gets(array);
    printf("Enter the number of element :");
    scanf("%d", &nidElement);
    printf("Enter your id :");
    while (getchar() != '\n')
        ;
    gets(id);
    int resize = nElement + nidElement+1;
    array = realloc(array, sizeof(char)*(resize));

    for (int i = nElement; i < resize; i++)
    {
        if (i == nElement)
        {
            array[i] = ' ';
        }
        else
        {
            array[i] = id[i - nElement - 1];
        }
    }

    printf("\n%s", array);
    return 0;
}