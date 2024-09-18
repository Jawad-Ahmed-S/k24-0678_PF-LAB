#include<stdio.h>
int main()
{
    char check;
    printf("Enter a operator");
    scanf(" %c", &check);
if(check>'A' && check<'Z'){
    printf("UPPERCASE..");
}
else if (check > 'a' && check < 'z')
{
    printf("lowercase..");
}
else if (check > '0' && check < '9')
{
    printf("Number..");
}
else
{
    printf("Special Character..");
}
printf("\n It's ASCII representation :%d",check);
    return 0;
}