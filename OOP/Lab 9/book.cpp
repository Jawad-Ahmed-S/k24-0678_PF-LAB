#include<iostream>
using namespace std;
#include "book.h"

Book::Book(string title,string author,string ISBN){
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
};

string Book::getTitle(){
    return title;
}
string Book::getAuthor(){
    return author;
}
string Book::getISBN(){
    return ISBN;
}