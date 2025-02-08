#include <stdio.h>
#include <stdlib.h>
int main()
{
    int nElement;
    printf("Enter the number of element you want to include in the array ");
    scanf("%d", &nElement);

    int *array = (int *)calloc(nElement, sizeof(int));

    int max = 0;
    for (int i = 0; i < nElement; i++)
    {
        printf("Enter the element\n");
        scanf("%d", &array[i]);
        if (max < array[i])
        {
            max = array[i];
        }
    }
    printf("Max = %d", max);
    int resize;
    printf("\nhow many elements you want to add");
    scanf("%d", &resize);
    resize += nElement;
    array = realloc(array, sizeof(int) * resize);

    for (int i = nElement; i < resize; i++)
    {
        printf("Enter the element\n");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < resize; i++)
    {
        printf("%d : %d\n", i + 1, array[i]);
    }
    return 0;
}