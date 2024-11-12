#include <stdio.h>
#include <string.h>
void palindrome(char arr[4][50], char temp[5]);
int main()
{

    char arr[4][50] = {"radar", "madam", "rajhar", "level"};
    char temp[5];
    palindrome(arr, temp);
}
void palindrome(char arr[4][50], char temp[5])
{
    
    int Palindrome[5] = {0};
    for (int i = 0; i < 4; i++)
    {
strcpy(arr[i],temp);
char reversed[5];
 reversed= strrev(arr[i]);
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
    }
}