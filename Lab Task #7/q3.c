#include <stdio.h>
int main()
{
    int count = 0;
    
    
    char str[] = "FAST";
    char *start=str;
    char *end=str;
   
    while (*end != '\0')
    {
        count++;
      end++;
    }
  end--;
    printf("%d", count);

  while(start<end){
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
  }

printf("%s",str);
    return 0;
}