#include <stdio.h>
int main()
{
    int count = 0;

    char str[] = "FAF";
    char *start = str;
    char *end = str;

    while (*end != '\0')
    {
        count++;
        end++;
    }
    end--;
    // printf("%d", count);

    while (start < end)
    {
        if (*start == *end)
        {
            start++;
            end--;
        }
        else
        {
            printf("It is not valid");
            break;
        }
    printf("It is a palindrome");
    }

    return 0;
}