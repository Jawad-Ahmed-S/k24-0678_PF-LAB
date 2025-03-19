#include <iostream>
using namespace std;
class Media
{
protected:
    int publicationDate;
    string title;
    int uniqueId;
    string publisher;

public:
    Media()
    {
        title = "No Title";
        publicationDate = 0;
        uniqueId = 0;
        publisher = "No Publisher";
    }
    Media(string title, int publicationDate, int uniqueId, string publisher)
    {
        this->title = title;
        this->publicationDate = publicationDate;
        this->uniqueId = uniqueId;
        this->publisher = publisher;
    }
    virtual void displayInfo() {};
    void checkout()
    {
        cout << "Checkout: " << title << endl;
    }
    void returnItem()
    {
        cout << "Return: " << title << endl;
    }
    string getTitle()
    {
        return title;
    }
    int getPublishDate()
    {
        return publicationDate;
    }
};
class Book : public Media
{
    string author;
    int ISBN;
    int noPages;

public:
    Book(string title, int publicationDate, int uniqueId, string publisher, string author, int ISBN, int noPages) : Media(title, publicationDate, uniqueId, publisher)
    {
        this->author = author;
        this->ISBN = ISBN;
        this->noPages = noPages;
    }
    void displayInfo() override
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueId << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "No of Pages: " << noPages << endl;
    }
    string getAuthor()
    {
        return author;
    }
};
class DVD : public Media
{
    string director;
    float duration;
    int rating;

public:
    DVD(string title, int publicationDate, int uniqueId, string publisher, string director, float duration, int rating) : Media(title, publicationDate, uniqueId, publisher)
    {
        this->director = director;
        this->duration = duration;
        this->rating = rating;
    }
    void displayInfo() override
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueId << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};
class CD : public Media
{
    string artist;
    int noTracks;
    string genre;

public:
    CD(string title, int publicationDate, int uniqueId, string publisher, string artist, int noTracks, string genre) : Media(title, publicationDate, uniqueId, publisher)
    {
        this->artist = artist;
        this->noTracks = noTracks;
        this->genre = genre;
    }
    void displayInfo() override
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueId << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Artist: " << artist << endl;
        cout << "No of Tracks: " << noTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};
class Library
{
    Media **m;
    int size;

public:
    Library()
    {
        size = 0;
        m = new Media *[size];
    }
    void addMedia(Media *med)
    {
        Media **temp = new Media *[size + 1];
        for (int i = 0; i <= size; i++)
            temp[i] = m[i];

        temp[size] = med;
        delete[] m;
        m = temp;
        size++;
        cout << "Media added successfully!" << endl;
    }
    void search(string title)
    {
        cout << "\nSearch Results for Title: " << title << endl;
        for (int i = 0; i < size; i++)
        {
            if (m[i]->getTitle().find(title) != string::npos)
            {
                m[i]->displayInfo();
            }
        }
    }
    void search(int date)
    {
        cout << "\nSearch Results for Date: " << date << endl;
        for (int i = 0; i < size; i++)
        {
            if (m[i]->getPublishDate() == date)
            {
                m[i]->displayInfo();
            }
        }
    }
};
int main()
{

    Library library;
    Book b("The Catcher in the Rye", 1951, 1, "J.D. Salinger", "J.D. Salinger", 0345, 275);
    DVD d("The father", 1972, 2, "Francis Ford Coppola", "Francis Ford Coppola", 1.52, 9.2);
    CD c("Thriller", 1982, 3, "Pink Floyd", "Pink Floyd", 13, "Thriller");
    library.addMedia(&b);
    library.addMedia(&d);
    library.addMedia(&c);
    library.search("The Catcher in the Rye");
    library.search(1972);

    return 0;
}