//
//  Book.cpp
//  library
//
//  Created by Skuli Þór Árnason on 24/05/16.
//  Copyright © 2016 Skuli Þór Árnason. All rights reserved.
//

#include "Book.hpp"

//Constructors
Book::Book(){
    this->ISBN = 0;
    this->pageCount = 0;
    this->title = "";
    this->checked = false;
}

Book::Book( string title, int ISBN, int pageCount, bool checked){
    this->ISBN = ISBN;
    this->pageCount = pageCount;
    this->title = title;
    this->checked = checked;
}

Book::~Book(){
    
}

//Getters
int Book::getISBN(){
    return this->ISBN;
}
int Book::getPageCount(){
    return this->pageCount;
}
string Book::getTitle(){
    return this->title;
}
bool Book::getChecked(){
    return this->checked;
}

//Setters
void Book::setISBN(int ISBN){
    this->ISBN = ISBN;
}
void Book::setPageCount(int pageCount){
    this->pageCount = pageCount;
}
void Book::setTitle(string title){
    this->title = title;
}
void Book::setChecked(bool checked){
    this->checked = checked;
}

void Book::setBook(Book book){
    this->ISBN = book.ISBN;
    this->title = book.title;
    this->pageCount = book.pageCount;
    this->checked = book.checked;
}

//Friends
ostream& operator <<(ostream& outs, const Book& book){
    outs << "Title: " << book.title << endl;
    outs << "ISBN: " << book.ISBN << endl;
    outs << "Page count: " << book.pageCount << endl;
    if(book.checked){
        outs << "Book is on loan." << endl;
    }else{
        outs << "Book is available" << endl;
    }
    
    return outs;
}