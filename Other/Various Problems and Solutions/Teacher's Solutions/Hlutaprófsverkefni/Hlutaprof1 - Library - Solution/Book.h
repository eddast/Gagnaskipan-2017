//
//  Book.hpp
//  library
//
//  Created by Skuli Þór Árnason on 24/05/16.
//  Copyright © 2016 Skuli Þór Árnason. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Book{
public:
    
    //Constructors
    Book();
    Book(string title, int ISBN, int pageCount, bool checked = false);
    ~Book();
    
    //Getters
    int getISBN();
    int getPageCount();
    string getTitle();
    bool getChecked();
    
    //Setters
    void setISBN(int ISBN);
    void setPageCount(int pageCount);
    void setTitle(string title);
    void setChecked(bool checked);
    void setBook(Book book);
    
    //Friends
    friend ostream& operator <<(ostream& outs, const Book& book);
    
private:
    int ISBN;
    int pageCount;
    string title;
    bool checked;
    
};

#endif /* Book_hpp */
