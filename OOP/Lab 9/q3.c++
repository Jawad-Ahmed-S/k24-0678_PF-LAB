#include "book.h"
#include<iostream>
using namespace std;
class Library{
    Book **books;
    int size;
    public:
    Library(int size){
        this->size = size;
        books = new Book*[size];
    }
    void addBook(Book *b){
        Book **temp = new Book*[size+1];
        for(int i=0;i<size;i++){
            temp[i] = books[i];
        }
        temp[size] = b;
        delete[] books;
        books = temp;
        size++;
    }
    void removeBook(string title){
        int index = -1;
        for(int i=0;i<size;i++){
            if(books[i]->getTitle() == title){
                index = i;
                break;
            }
        }
        if(index == -1){
            cout<<"Book not found"<<endl;
            return;
        }
        Book **temp = new Book*[size-1];
        for(int i=0;i<index;i++){
            temp[i] = books[i];
        }
        for(int i=index+1;i<size;i++){
            temp[i-1] = books[i];
        }
        delete[] books;
        books = temp;
        size--;
        }
        Book *searchBook(string title){
            for(int i=0;i<size;i++){
                if(books[i]->getTitle() == title){
                    return books[i];
                }
            }
            return NULL;
        }
    };
    int main(){
        Library l(3);
        Book b1("The Great Gatsby","F. Scott Fitzgerald","978-0743273565");
        Book b2("To Kill a Mockingbird","Harper Lee","978-0061120084");
        Book b3("1984","George Orwell","978-0451524935");
        l.addBook(&b1);
        l.addBook(&b2);
        l.addBook(&b3);
        l.removeBook("To Kill a Mockingbird");
        Book *b = l.searchBook("1984");
        if(b != NULL){
            cout<<"Book found: "<<b->getTitle()<<endl;
        }
        else{
            cout<<"Book not found"<<endl;
        }
        return 0;
    }
