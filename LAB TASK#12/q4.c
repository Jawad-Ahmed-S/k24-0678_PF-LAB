#include <stdio.h>
#include <stdlib.h>
int main()
{
    int nElement;
    printf("Enter the number of element you want to include in the array ");
    scanf("%d", &nElement);

    char *array = (char *)calloc(nElement, sizeof(char));
    printf("Enter your name");
    while (getchar() != '\n');
    gets(array);

    printf("%s", array);
    return 0;
}