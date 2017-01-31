#include <iostream>
#include "StringList.h"
#include <string>

using namespace std;

void testEmptyCurr()
{
    /*cout << endl << "-- Testing empty list -- " << endl;
    StringList s4;
    cout << "Curr pos of an empty list: " << s4.curr_pos() << endl;
    s4.append("u");
    s4.remove();
    s4.prev();
    s4.prev();
    s4.prev();
    s4.prev();
    cout << "Curr pos of an empty list: " << s4.curr_pos() << endl;*/
    StringList s4;
    cout << "currpos: " << s4.curr_pos() << endl;
    s4.insert("pod");
    cout << "currpos: " << s4.curr_pos() << endl;
    cout << "calling prev..." << endl;
    s4.prev();
    cout << "currpos: " << s4.curr_pos() << endl;
    cout << "Inserting node..." << endl;
    s4.insert("ah");
    cout << "currpos: " << s4.curr_pos() << endl;
    cout << s4 << endl;
    cout << "Calling next..." << endl;
    s4.next();
    cout << "currpos: " << s4.curr_pos() << endl;
    //s4.remove();
    cout << s4 << endl;

}

void testRemove()
{
    cout << "--Testing remove--" << endl;
    StringList s3;
    s3.insert("1");
    s3.insert("2");
    s3.insert("3");
    s3.insert("4");
    s3.insert("5");
    cout << "List: " << s3 << endl;
    s3.move_to_pos(3);
    cout << "Remove element: " << s3.remove() << endl;
    cout << "Removed 3rd node: " << s3 << endl;
}

void testMovetoPos()
{
    cout << "--Testing move-to-pos--" << endl;
    StringList s2;
    s2.insert("e");
    s2.insert("d");
    s2.insert("c");
    s2.insert("b");
    s2.insert("a");
    cout << s2 << endl;
    s2.move_to_pos(3);
    cout << "Value of curr[3]: " << s2.get_value() << endl;
    s2.move_to_pos(4);
    cout << "Value of curr[4]: " << s2.get_value() << endl;
    s2.move_to_pos(1);
    cout << "Value of curr[1]: " << s2.get_value() << endl;
    s2.move_to_pos(5);
    try {s2.move_to_pos(9);} catch(InvalidPositionException) {cout << "Invalid position 9" << endl;}
    try {s2.move_to_pos(0);} catch(InvalidPositionException) {cout << "Invalid position 0" << endl;}
    try {s2.move_to_pos(-1);} catch(InvalidPositionException) {cout << "Invalid position -1" << endl;}
    cout << endl;
}

void testClear()
{
    StringList testlist;
    cout << "calling movetostart" << endl;
    //testlist.move_to_start();
    cout << "calling clear" << endl;
    //testlist.clear();
    cout << "inserting" << endl;
    testlist.insert("a");
    cout << testlist << endl;
}

void testInsertandMore()
{
    cout << "-- Testing insert -- " << endl;
    StringList s1;
    cout << "Length: " << s1.length() << endl;
    s1.append("testAppend");
    s1.insert("1");
    cout << "add one: " << s1 << endl;
    cout << "Current pos: " << s1.curr_pos() << endl;
    cout << "Length: " << s1.length() << endl;
    s1.append("testAppend");
    s1.insert("2");

    cout << "add two: " << s1 << endl;
    cout << "Current pos: " << s1.curr_pos() << endl;
    cout << "Length: " << s1.length() << endl;
    s1.insert("3");
    s1.append("testAppend");
    //s1.move_to_end();
    cout <<"add three: " << s1 << endl;
    cout << "Current pos: " << s1.curr_pos() << endl;
    cout << "Length: " << s1.length() << endl;
    s1.insert("4");
    s1.move_to_start();
    cout << "add four: " << s1 << endl;
    cout << "Current pos: " << s1.curr_pos() << endl;
    cout << "Length: " << s1.length() << endl;
    s1.clear();
    cout << endl;
}

int main()
{
    testInsertandMore();
    testMovetoPos();
    testRemove();
    testEmptyCurr();
    testClear();

}
