// Q5
#include <stdio.h>
#include <string.h>
void reverseStr(char str[15]);
int main()
{
    char str[50];
    printf("Enter a string");
    scanf("%s", str);
    reverseStr(str);

    printf("%s", str);
}
void reverseStr(char str[15])
{
    int length = strlen(str);
    int last = length;
    int i;
    int temp;
    for (i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[last - 1];
        str[last - 1] = temp;
        last--;
    }
}