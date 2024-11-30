#include <stdio.h>
#include <string.h>
int main()
{
    char temp[100];
    FILE *fptr = fopen("sample.txt", "r");
    if (fptr == NULL)
    { // Check if file was opened successfully
        perror("Error opening file");
        return 1;
    }
    fread(temp,sizeof(char),sizeof(temp)-1,fptr);

    fclose(fptr);
    printf("%s", temp);

    temp[sizeof(temp) - 1] = '\0';
    FILE *fptrW = fopen("samplee.txt", "w+");
    fprintf(fptrW, "%s", temp);
    fclose(fptrW);

    return 0;
}