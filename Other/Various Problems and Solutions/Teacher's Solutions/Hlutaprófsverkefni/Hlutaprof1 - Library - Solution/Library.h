//
//  Library.hpp
//  library
//
//  Created by Skuli Þór Árnason on 24/05/16.
//  Copyright © 2016 Skuli Þór Árnason. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp

#include <stdio.h>
#include "Book.hpp"


class Library{
public:
    
    //Constructors
    Library();
    Library(int bookCount);
    ~Library();
    
    //Functions
    void addBook(Book book);
    void checkOutBookByISBN(int ISBN);
    void checkOutBookByTitle(string title);
    void returnBookByISBN(int ISBN);
    void returnBookByTitle(string title);
    void listBooks();
    
private:
    Book& getBookByTitle(string title);
    Book& getBookByISBN(int ISBN);
    Book* books;
    int bookCount;
};

#endif /* Library_hpp */
