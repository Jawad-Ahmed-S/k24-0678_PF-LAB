#include <stdio.h>
#include <string.h>
void palindrome(const char arr[4][50], char temp[5]);
void reverseStr(char str[15]);
int main()
{
    char arr[4][50] = {"radar", "madam", "rajhar", "level"};
    char temp[5];

    palindrome(arr, temp);
    return 0;
}
void palindrome(const char arr[4][50], char temp[5])
{

    int Palindrome[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        strcpy(temp, arr[i]);
        reverseStr(temp);
        if (strcmp(arr[i], temp) == 0)
        {
            Palindrome[i] = 1;
        }
    }

    for (int j = 0; j < 4; j++)
    {

        if (Palindrome[j] == 1)
        {
            printf("%s : is palindrome \n", arr[j]);
        }
        else
        {
            printf("%s : is not a palindrome \n", arr[j]);
        }
    }
}

//as string reverse function was not working correctly i had to define it on my own
void reverseStr(char str[15])
{
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
