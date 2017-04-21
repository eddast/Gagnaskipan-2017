//
//  Library.cpp
//  library
//
//  Created by Skuli Þór Árnason on 24/05/16.
//  Copyright © 2016 Skuli Þór Árnason. All rights reserved.
//

#include "Library.hpp"
#include <exception>

/*class notFoundException: public exception
{
    virtual const char* what() const throw()
    {
        return "Book not found!";
    }
} notFoundException;*/

//Constructors
Library::Library(){
    this->books = NULL;
    this->bookCount = 0;
}

Library::Library(int bookCount){
    this->books = new Book[bookCount];
    this->bookCount = bookCount;
    for (int i = 0; i < bookCount; i++) {
        books[i] = Book();
    }
}

Library::~Library(){
    delete[] books;
}

//Functions
//Two books in the may not have the same title, they may have the same ISBN. 
/*void Library::addBook(Book book){
    try {
        getBookByTitle(book.getTitle());
        cout << "Book with title " << book.getTitle()<< "  already in library!" << endl;
    } catch (exception& e) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getISBN() == 0) {
                books[i].setBook(book);
                cout << book.getTitle() << " added to library!" << endl;
                return;
            }
        }
        cout << "Library is full!" << endl;
    }
}

void Library::checkOutBookByISBN(int ISBN){
    try {
        Book& book = getBookByISBN( ISBN);
        if (book.getChecked()) {
             cout << book.getTitle() << " is already checked out!" << endl;
        }else{
            book.setChecked(true);
             cout << book.getTitle() << " is now checked out!" << endl;
        }
        return;
    } catch (exception& e) {
        cout << e.what() << endl;
        return;
    }
    
}

void Library::checkOutBookByTitle(string title){
    try {
        Book& book = getBookByTitle(title);
        if (book.getChecked()) {
            cout << book.getTitle() << " is already checked out!" << endl;
        }else{
            book.setChecked(true);
            cout << book.getTitle() << " is now checked out!" << endl;
        }
        return;
    } catch (exception& e) {
        cout << e.what() << endl;
        return;
    }
}

void Library::returnBookByISBN(int ISBN){
    try {
        Book& book = getBookByISBN(ISBN);
        if (book.getChecked()) {
            book.setChecked(false);
            cout << book.getTitle() << " has been returned!" << endl;
        }else{
            cout << book.getTitle() << " is already in library!" << endl;
        }
        return;
    } catch (exception& e) {
        cout << e.what() << endl;
        return;
    }
}

void Library::returnBookByTitle(string title){
    try {
        Book& book = getBookByTitle(title);
        if (book.getChecked()) {
            book.setChecked(false);
            cout << book.getTitle() << " has been returned!" << endl;
        }else{
            cout << book.getTitle() << " is already in library!" << endl;
        }
        return;
    } catch (exception& e) {
        cout << e.what() << endl;
        return;
    }
}*/

void Library::addBook(Book book){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle() == book.getTitle()) {
             cout << "Book with title " << book.getTitle()<< "  already in library!" << endl;
            return;
        }
    }
    
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getISBN() == 0) {
            books[i].setBook(book);
            cout << book.getTitle() << " added to library!" << endl;
            return;
        }
    }
    cout << "Library is full!" << endl;
    
}

void Library::checkOutBookByISBN(int ISBN){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getISBN()== ISBN) {
            if (books[i].getChecked()) {
                cout << books[i].getTitle() << " is already checked out!" << endl;
            }else{
                books[i].setChecked(true);
                cout << books[i].getTitle() << " is now checked out!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::checkOutBookByTitle(string title){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle()== title) {
            if (books[i].getChecked()) {
                cout << books[i].getTitle() << " is already checked out!" << endl;
            }else{
                books[i].setChecked(true);
                cout << books[i].getTitle() << " is now checked out!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::returnBookByISBN(int ISBN){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getISBN()== ISBN) {
            if (books[i].getChecked()) {
                books[i].setChecked(false);
                cout << books[i].getTitle() << " has been returned!" << endl;
            }else{
                cout << books[i].getTitle() << " is already in library!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::returnBookByTitle(string title){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle()== title) {
            if (books[i].getChecked()) {
                books[i].setChecked(false);
                cout << books[i].getTitle() << " has been returned!" << endl;
            }else{
                cout << books[i].getTitle() << " is already in library!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::listBooks(){
    for (int i = 0; i < bookCount; i++) {
        if(books[i].getTitle() != ""){
            cout << books[i] << endl;
        }else{
            cout << "No book in place " << i << "!" << endl;
        }
    }
}

/*Book& Library::getBookByTitle(string title){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle() == title) {
            return books[i];
        }
    }
    throw notFoundException;
}

Book& Library::getBookByISBN(int ISBN){
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getISBN()== ISBN) {
            return books[i];
        }
    }
    throw notFoundException;
}*/

