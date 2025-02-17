#include <stdio.h>
#include <string.h>
struct Book
{
    char title[10];
    char author[10];
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
        if (strcmp(O1[i].title, search) == 0)
        {
            printf("Book is %s\n", O1[i].title);
            printf("Author is %s\n", O1[i].author);
            printf("Publishing Year is %d\n", O1[i].Publishing_year);
            printf("Price is %d\n", O1[i].price);
        }
    }
}
void FindBookByAuthor(struct Book O1[], char author[10])
{
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(O1[i].author, author) == 0)
        {
            printf("Book is %s\n", O1[i].title);
            printf("Author is %s\n", O1[i].author);
            printf("Publishing Year is %d\n", O1[i].Publishing_year);
            printf("Price is %d\n", O1[i].price);
        }
    }
}
int main()
{

    struct Book O1[4] = {
        {"Book1", "ABC", 2024, 100},
        {"Book2", "DSC", 2023, 500},
        {"Book3", "DSC", 2020, 105},
        {"Book4", "BAC", 2021, 1000},
    };
    SearchBook(O1, "Book1");
    FindBookByAuthor(O1, "DSC");
    return 0;
}