/* Lab 2: String List
 * Due: 29.01.17
 * Class: Gagnaskipan 2017
 * Solution: Edda Steinunn and Bergvin Örn
 * StringList.cpp file
 */

#include "StringList.h"

// Initializes empty list
StringList::StringList()
{
    // Head and tail nodes created
    head = new StringNode ("", tail, NULL);
    tail = new StringNode ("", NULL, head);
    // Curr pointer set to tail for an empty list
    curr = tail;
    // Size is 0 and currPos set to 0 as well
    ListSize = 0;
    currPos = 0;
}

// Deletes list completely
StringList::~StringList()
{
    // Delete all nodes with values
    clear();

    // Then delete head and tail nodes
    delete head;
    delete tail;
}

// Clears contents
 void StringList::clear()
{
    // No action if list is empty already
    if(!isEmpty())
    {
        // node points to first node
        NodePtr node = head->next;
        while(node != tail)
        {
            // De-attach head from next node to node after
            head->next = node->next;
            // Delete node before
            delete node;
            // Node then becomes first node in list again
            node = head->next;
        }

        // Size of list becomes 0
        ListSize = 0;

        // Head now points to tail and tail points to head
        head->next = tail;
        tail->prev = head;

        // Curr set to default
        curr = tail;

        // Position shifts back to 0
        currPos = 0;
    }
}

// Inserts element at current location
void StringList::insert(const string& item)
{
    // New node to be inserted created
    NodePtr node = new StringNode(item, curr, (curr->prev));

    // Pointers on curr set to node
    (curr->prev)->next = node;
    curr->prev = node;

    // Curr then set to node
    curr = node;

    // Size of list increases by one after insertion
    ListSize++;
}

// Appends element at end of list
void StringList::append(const string& item)
{
    // New node stores item and points to tail and node before tail
    NodePtr node = new StringNode(item, tail, (tail->prev));

    // Fixing "attachments" from node before and behind
    (tail->prev)->next = node;
    tail->prev = node;

    // List size increases by one
    ListSize++;

    // In the end, sets curr as node if it is tail
    if(curr == tail)
    {
        curr = node;
    }
}

// Removes and returns current element.
string StringList::remove()
{
    // Position out of range throws exception
    if(isEmpty() || currPos >= ListSize)
    {
        throw InvalidPositionException();
    }
    else
    {
        // New pointer points to curr
        NodePtr ptr = curr;
        //Curr increases by one
        curr = curr->next;

        //Element to return
        string removedElem = ptr->data;

        //Fixing "attachments" around removed node
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;

        // Temporary pointer deleted and list decreases
        delete ptr;
        ListSize--;

        return removedElem;
    }
}

// Sets current position at start of list
void StringList::move_to_start()
{
    // Actions made only if list is not empty
    if(!isEmpty())
    {
        // Current set to first node
        // current position set to 0
        curr = head->next;
        currPos = 0;
    }
}

// Sets current position at end of list
void StringList::move_to_end()
{
    // Action only if list is not empty
    if(!isEmpty())
    {
        // Curr set to tail
        // Current position set to list size (tail)
        curr = tail;
        currPos = ListSize;
    }
}

// Moves the current position left
void StringList::prev()
{
    // Must stay in scope
    if (curr->prev != head)
    {
        // Curr set to previous node
        // Current position decreases by one
        curr = curr->prev;
        currPos--;
    }
}

// Moves the current position right
void StringList::next()
{
    // Curr cannot be tail
    if (curr != tail)
    {
        // Curr points to next node
        // Current position increases by one
        curr = curr->next;
        currPos++;
    }
}

// Returns number of elements in list.
int StringList::length() const
{
    return ListSize;
}

// Returns position of current element.
int StringList::curr_pos() const
{
    return currPos;
}

// Sets current position
void StringList::move_to_pos(int pos)
{
    // Need to stay in scope of list
    if(pos > ListSize || pos < 0)
    {
        throw InvalidPositionException();
    }
    else
    {
        // Curr set to first node
        curr = head->next;
        currPos = pos;
        // Iterate to position, placing curr pointer there
        for (int i = 0; i < currPos; i++)
        {
            curr = curr->next;
        }
    }
}

// Returns current element.
 const string& StringList::get_value() const
{
    // Need to stay in scope
    if(currPos >= ListSize)
    {
        throw InvalidPositionException();
    }
    else
    {
        return curr->data;
    }
}


// Outputs elements of list
ostream& operator <<(ostream& outs, const StringList& lis)
{
    // New node as first node
    NodePtr node = lis.head->next;
    while(node != lis.tail){
        // Outputs data of nodes while iterating through list
        outs << node->data;
        if (node->next != lis.tail)
        {
            outs << " ";
        }
        node = node->next;
    }
    return outs;
}

// Simple bool check if size is 0 - list is empty
bool StringList::isEmpty()
{
    return ListSize == 0;
}

