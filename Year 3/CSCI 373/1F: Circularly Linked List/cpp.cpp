#include <stdio.h>
#include "Header.h"

CircleList::CircleList() //Definition of construstor.
: cursor(NULL) { } //Creates linked list with empty cursor.

CircleList::~CircleList() //Definition of destructor.
{ while (!empty()) remove(); } //Loop that removes node until the list is empty.

bool CircleList::empty() const //Definition of empty() function.
{ return cursor == NULL; } //Checks if the list is empty.

const Elem& CircleList::back() const //Definition of back() function.
{ return cursor -> elem; } //Returns the element at the cursor.

const Elem& CircleList::front() const //Definition of front() function.
{ return cursor -> next -> elem; } //Returns the element after the cursor.

void CircleList::advance() //Definition of advance() function.
{ cursor = cursor -> next; } //Advances the cursor to next node in linked list.

void CircleList::add(const Elem& e) //Definition of add() function.
{
    CNode* v = new CNode; //Creates a new node to be added in linked list.
    v -> elem = e; //Stores given element inside new node.
    
    if (cursor == NULL) //Checks if the list is empty
    {
        v -> next = v; //Node v will point to itself.
        cursor = v; //The cursor is pointing to node v.
    }
    
    else //If the list is not empty.
    {
        v -> next = cursor -> next; //Node v will be linked in after the cursor.
        cursor -> next = v; //The cursor's next it set to node v.
    }
}

void CircleList::remove() //Definition of remove() function.
{
    CNode* old = cursor -> next; //Provides the node that will be removed.
    
    if (old == cursor) //Checks if the node to be removed is the only node in list.
        cursor = NULL; //The list becomes empty.
    
    else //If there are other nodes in linked list.
        cursor -> next = old -> next; //Links out the old node.
    
    delete old; //Deletes the node.
}
