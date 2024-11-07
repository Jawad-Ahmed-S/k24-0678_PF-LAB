#include <stdio.h>
int main()
{
    int i = 45;
    int prime(int i);
    int isprime = prime(i);
    if (isprime)
        printf("prime");

    else
    {
        printf("not prime");
    }
    return 0;
}
int prime(int i)
{
    int prime = 1;

    if (i < 2)
    {
        prime = 0;
    }
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            prime = 0;
            break;
        }
    }
    return prime;
}
