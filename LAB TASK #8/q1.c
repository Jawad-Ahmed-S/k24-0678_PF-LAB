#include <stdio.h>
int main()
{
    int start, end;
    printf("Enter starting value");
    scanf("%d", &start);
    printf("Enter ending value");
    scanf("%d", &end);
    for (int i = start; i <=end; i++)
    {
    int prime = 1;

    if(i<2){
      continue;
    }
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime)
            printf("%d ", i);
    }
    return 0;
}