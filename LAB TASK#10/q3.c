#include <stdio.h>
#include <string.h>
struct Book
{
    char title[5];
    char author[5];
    int Publishing_year;
    int price;
};
void display(struct Book O1[])
{
    for (int i = 0; i < 4; i++)
    {
        printf("%d : %s \n", i + 1, O1[i].title);
    }
}

void SearchBook(struct Book O1[], char search[5])
{
    for (int i = 0; i < 4; i++)
    {
        printf("%s : %s\n", search, O1[i].title);
        if (strcmp(O1[i].title, search) == 0)
        {
            printf("Book is %s\n", O1[i].title);
            printf("Book is %s\n", O1[i].author);
            printf("Book is %d\n", O1[i].Publishing_year);
            printf("Book is %d\n", O1[i].price);
        }
        else{
            printf("Nothing found like that");
        }
    }
}
int main()
{

    struct Book O1[4] = {
        {"Book1", "ABC", 2024, 100},
        {"Book2", "DSC", 2023, 500},
        {"Book3", "ADC", 2020, 105},
        {"Book4", "BAC", 2021, 1000},
    };
    //  display(O1);
    char search[5];
    strcpy(search, "Book1");
    SearchBook(O1, search);
    return 0;
}