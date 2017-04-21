//
//  main.cpp
//  library
//
//  Created by Skuli Þór Árnason on 24/05/16.
//  Copyright © 2016 Skuli Þór Árnason. All rights reserved.
//

#include <iostream>
#include "Library.hpp"

//Duplicate books not allowed as of yet!

int main(int argc, const char * argv[]) {

    Book book1("The Fellowship of the Ring", 1338, 600);
    cout << book1;
    
    Book book2("The Way of Kings", 1337, 800);
    cout << book2;
    
    Book book3("The Windup Bird Chronicle", 9000, 700);
    cout << book3;
    
    Book book4("The Alloy of Law", 87665, 300);
    cout << book4;
    
    
    Library library(3);
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    
    library.listBooks();
    
    library.checkOutBookByISBN(1337);
    library.checkOutBookByISBN(1000);
    
    library.checkOutBookByTitle("The Way of Kings");
    library.checkOutBookByTitle("The Way of Nerds");
    
    library.returnBookByISBN(1338);
    library.returnBookByISBN(87665);
    
    library.returnBookByTitle("The Way of Kings");
    library.returnBookByTitle("The Alloy of Law");
    
    Book book01("1", 1, 1);
    Book book02("2", 2, 2);
    Book book03("3", 3, 3);
    Book book04("4", 4, 4);
    Book book05("5", 5, 5);
    Book book06("6", 6, 6);
    Book book07("7", 7, 7);
    Book book08("8", 8, 8);
    Book book09("9", 9, 9);
    Book book10("10", 10, 10);
    
    
    Library library2(10);
    
    library2.addBook(book01);
    library2.addBook(book02);
    library2.addBook(book03);
    library2.addBook(book04);
    library2.addBook(book05);
    library2.addBook(book06);
    library2.addBook(book07);
    library2.addBook(book08);
    library2.addBook(book09);
    library2.addBook(book01); // No book in place 9
    
    library2.listBooks();
    
    library2.checkOutBookByISBN(11);  //Book not found
    library2.checkOutBookByISBN(1);   //1 is not checked out
    library2.checkOutBookByISBN(1);   //1 is already checked out
    library2.returnBookByISBN(1);     //1 has been returned
    library2.returnBookByISBN(1);     //1 is already in library
    
    library2.checkOutBookByTitle("11");  //Book not found
    library2.checkOutBookByTitle("1");   //1 is not checked out
    library2.checkOutBookByTitle("1");   //1 is already checked out
    library2.returnBookByTitle("1");     //1 has been returned
    library2.returnBookByTitle("1");     //1 is already in library
    
    return 0;
}
