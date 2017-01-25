/*
 *
 *
 */
#include "StringList.h"

//Initializes the empty list
StringList::StringList()
{
    head = new StringNode ("", tail, NULL);
    tail = new StringNode ("", NULL, head);
    curr = tail;
    PtrSize = 0;
    currPos = 0;
}

StringList::~StringList()
{
    clear();
    delete head;
    delete tail;
}

// Clear contents from the list, to make it empty.
// Worst-case time complexity: Linear
 void StringList::clear()
{
    if(!isEmpty())
    {
        NodePtr node = head->next;
        while(node != tail)
        {
            head->next = node->next;
            //node->next->prev = head;
            delete node;
            node = head->next;
        }
        PtrSize = 0;
        head->next = tail;
        tail->prev = head;
        curr = tail;
        currPos = 0;
    }
}

// Insert an element at the current location.
// item: The element to be inserted
// Worst-case time complexity: Constant
void StringList::insert(const string& item)
{
    NodePtr node = new StringNode(item, curr, (curr->prev));

    (curr->prev)->next = node;
    curr->prev = node;

    curr = node;

    PtrSize++;
}

// Append an element at the end of the list.
// item: The element to be appended.
// Worst-case time complexity: Constant
void StringList::append(const string& item)
{

    NodePtr node = new StringNode(item, tail, (tail->prev));
    (tail->prev)->next = node;
    tail->prev = node;

    PtrSize++;

    if(curr == tail)
    {
        curr = node;
        //currPos = PtrSize - 1;
    }
}

// Remove and return the current element.
// Return: the element that was removed.
// Worst-case time complexity: Constant
// Throws InvalidPositionException if current position is
// behind the last element
string StringList::remove()
{
    if(isEmpty() || currPos >= PtrSize)
    {
        throw InvalidPositionException();
    }
    else
    {
        NodePtr ptr = curr;
        curr = curr->next;

        string removedElem = ptr->data;

        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;

        delete ptr;
        PtrSize--;

        return removedElem;
    }
}

// Set the current position to the start of the list
// Worst-case time complexity: Constant
void StringList::move_to_start()
{
    if(!isEmpty())
    {
        curr = head->next;
        currPos = 0;
    }
}

// Set the current position to the end of the list
// Worst-case time complexity: Constant
void StringList::move_to_end()
{
    if(!isEmpty())
    {
        curr = tail;
        currPos = PtrSize;
    }
}

// Move the current position one step left. No change
// if already at beginning.
// Worst-case time complexity: Constant
void StringList::prev()
{
    if (curr->prev != head)
    {
        curr = curr->prev;
        currPos--;
    }
}

// Move the current position one step right. No change
// if already at end.
// Worst-case time complexity: Constant
void StringList::next()
{
    if (curr != tail)
    {
        curr = curr->next;
        currPos++;
    }
}

// Return: The number of elements in the list.
// Worst-case time complexity: Constant
int StringList::length() const
{
    return PtrSize;
}

// Return: The position of the current element.
// Worst-case time complexity: Constant
int StringList::curr_pos() const
{
    return currPos;
}

// Set current position.
// pos: The position to make current.
// Worst-case time complexity: Linear
// Throws InvalidPositionException if 'pos' is not a valid position
void StringList::move_to_pos(int pos)
{
    if(pos > PtrSize || pos < 0)
    {
        throw InvalidPositionException();
    }
    else
    {
        curr = head->next;
        currPos = pos;
        for (int i = 0; i < currPos; i++)
        {
            curr = curr->next;
        }
    }
}

// Return: The current element.
// Worst-case time complexity: Constant
// Throws InvalidPositionException if current position is
// behind the last element
 const string& StringList::get_value() const
{
    if(currPos >= PtrSize)
    {
        throw InvalidPositionException();
    }
    else
    {
        return curr->data;
    }
}


// Outputs the elements of 'lis' to the stream 'outs', separated
// by a single space.
ostream& operator <<(ostream& outs, const StringList& lis)
{
    NodePtr node = lis.head->next;
    // While list "lasts"
    while(node != lis.tail){
        outs << node->data;
        if (node->next != lis.tail)
        {
            outs << " ";
        }
        node = node->next;
    }
    return outs;
}

bool StringList::isEmpty()
{
    return PtrSize == 0;
}

