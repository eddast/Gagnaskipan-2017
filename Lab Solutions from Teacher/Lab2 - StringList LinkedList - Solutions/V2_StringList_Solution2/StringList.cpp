#include <iostream>
#include <stdio.h>
#include "StringList.h"

StringList::StringList() {
    size = 0;
    first = NULL;
    last = NULL;
    current = NULL;
    currentPosition = 0;
}

StringList::~StringList() {
    clear();
}

void StringList::clear() {
    StringNode *tmpNode = first;
    while(first != NULL) {
        tmpNode = first;
        first = first->next;
        delete tmpNode;
    }
    current = last = NULL;
    size = 0;
    currentPosition = 0;
}


void StringList::insert(const string& item) {

    if(current == NULL) {
        append(item);
    }
    else {
        StringNode *newNode = new StringNode(item, current, current->prev);
        if(current == first) {
            first = newNode;
        }
        else {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        current = newNode;
        size++;
    }

}

void StringList::append(const string& item) {
    StringNode *newNode = new StringNode(item, NULL, last);
    if(size == 0) {
        current = first = newNode;
    }
    else {
        last->next = newNode;
    }
    last = newNode;
    if(currentPosition == size) {
        current = newNode;
    }
    size++;
}

string StringList::remove() {

    if(current == NULL) {
        throw InvalidPositionException();
    }

    string returnData = current->data;

    if(current == last) {
        if(current != first) {
            current->prev->next = NULL;
            last = current->prev;
        }
        else {
            first = last = NULL;
        }
        delete current;
        current = NULL;
    }
    else {
        StringNode *nextCurrent = current->next;

        if(current == first) {
            first = nextCurrent;
            nextCurrent->prev = NULL;
            delete current;
            current = nextCurrent;
        }
        else {
            current->prev->next = nextCurrent;
            nextCurrent->prev = current->prev;
            delete current;
            current = nextCurrent;
        }
    }

    size--;
    return returnData;
}

void StringList::move_to_start() {
    current = first;
    currentPosition = 0;
}

void StringList::move_to_end() {
    currentPosition = size;
    current = NULL;
}

void StringList::prev() {
    if(current != first) {
        if(current == NULL){
            current = last;
        }
        else {
            current = current->prev;
        }
        currentPosition--;
    }
}

void StringList::next() {
    if(current != NULL) {
        current = current->next;
        currentPosition++;
    }
}

int StringList::length() const {
    return size;
}

int StringList::curr_pos() const {
    return currentPosition;
}

void StringList::move_to_pos(int pos) {
    if(pos < 0 || pos > size) {
        throw InvalidPositionException();
    }
    while(pos < currentPosition) {
        prev();
    }
    while(pos > currentPosition) {
        next();
    }
}

const string& StringList::get_value() const {
    if(current == NULL) {
        throw InvalidPositionException();
    }
    return current->data;
}

ostream& operator <<(ostream& outs, const StringList& lis) {

    StringNode *tmpNode = lis.first;
    while(tmpNode != NULL) {
        outs << tmpNode->data << " ";
        tmpNode = tmpNode->next;
    }
    return outs;
}
