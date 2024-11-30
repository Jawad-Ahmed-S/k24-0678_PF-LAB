#include <stdio.h>
#include <string.h>
int main()
{
    char word[10];
    char temp[100] = {0};
    char replace[] = "NEWWORD";
    char tofind[] = "This";
    char newContent[100] = {0};
    FILE *fptrR = fopen("sample.txt", "r");
    if (fptrR == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    fread(temp, sizeof(char), sizeof(temp) - 1, fptrR);
    fclose(fptrR);
    printf("TEMP :%s\n", temp);

    int j = 0, i = 0;
    while (temp[i] != '\0')
    {
        if (temp[i] != ' ' && temp[i] != '\n')
        {
            word[j] = temp[i];
            i++;
            j++;
        }
        else
        {
            word[j] = '\0';
            if (strcmp(tofind, word) == 0)
            {

                strcat(newContent, replace);
            }
            else
            {

                strcat(newContent, word);
            }

            strncat(newContent, &temp[i], 1);
            i++;
            j = 0;
        }
    }
    if (j > 0)
    {
        word[j] = '\0';
        if (strcmp(tofind, word) == 0)
        {
            strcat(newContent, replace);
        }
        else
        {
            strcat(newContent, word);
        }
    }

    printf("\nNEW : %s", newContent);
    return 0;
}