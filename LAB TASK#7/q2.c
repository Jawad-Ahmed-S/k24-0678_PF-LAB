#include <stdio.h>
int main()
{
    char str[10];
    int count[5] = {0};
    char var[5] = {'a', 'e', 'i', 'o', 'u'};
    printf("Enter a string");
    gets(str);
    for (int i = 0; i < 10; i++)
    {
        if (str[i] == 'a')
        {
            count[0]++;
        }

        else if (str[i] == 'e')
        {
            count[1]++;
        }
        else if (str[i] == 'i')
        {
            count[2]++;
        }
        else if (str[i] == 'o')
        {
            count[3]++;
        }
        else if (str[i] == 'u')
        {
            count[4]++;
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%c : %d \n", var[i], count[i]);
    }
    return 0;
}