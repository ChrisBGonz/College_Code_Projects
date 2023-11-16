#include <stdio.h>
#include "header.h"
#include <iostream>
#include <stdexcept> //This library is needed to use std::runtime_error() function.
using namespace std;

const Elem& CNode::getElement() const 
{
    return elem;
}

CNode* CNode::getNext() const 
{
    return next;
}

CircleList::CircleList() //Definition of constructor.
: cursor(NULL) { } //Creates linked list with empty cursor.

CircleList::~CircleList() //Definition of destructor.
{ while (!empty()) remove(); } //Loop that removes node until the list is empty.

bool CircleList::empty() const //Definition of empty() function.
{ return cursor == NULL; } //Checks if the list is empty.

const Elem& CircleList::back() const //Definition of back() function.
{ return cursor -> elem; } //Returns the element at the cursor.

const Elem& CircleList::front() const //Definition of front() function.
{
    if (cursor == NULL) {
        throw std::runtime_error("Error: List is empty. Unable to perform front function.");
    }
    return cursor -> next -> elem; //Returns the element after the cursor.
}

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

CNode* CircleList::getCursor() const //Definition of getCursor() function.
{
    return cursor; //Returns the cursor.
}

/*
 Note: Variable cursor is a private data member. This function allows the code to use the cursor without directly accessing it. This function will be necessary for the display_queue() function.
*/

LinkedQueue::LinkedQueue() //Definition of linked queue constructor.
: C(), n(0) { } //Initializes private data members.

int LinkedQueue::size() const //Definition of size() function.
{ return n; } //Returns the number of items in the queue.

bool LinkedQueue::empty() const //Definition of empty() function.
{ return n == 0; } //Checks if the queue is empty.

const Elem& LinkedQueue::front() const //Definition of the front() function.
{
    if (empty()) //Checks if the queue is empty before returning front item.
        throw std::runtime_error("Error: Queue is empty. Unable to perform front function."); //Exception handling.
    
    return C.front(); //If the queue is not empty, the function will return item at the front.
}

void LinkedQueue::enqueue(const Elem &e) //Definition of enqueue() function.
{
    C.add(e); //Invokes add() function from circularly linked list to add elements.
    C.advance(); //Advances circularly linked list cursor.
    n++; //Increments the total number of items in queue by 1.
    
    display_queue(); //Every time enqueue() is used, it will print out all the elements currently in the queue.
}

void LinkedQueue::dequeue() //Definition of dequeue() function.
{
    if (empty()) //Checks if the queue is empty using empty() function.
        throw std::runtime_error("Error: Queue is empty. Unable to perform dequeue function."); //Exception handling.
    
    C.remove(); //Removes the item from queue using circularly linked list remove() function.
    n--; //Decrements the total number of items in queue by 1.

    display_queue(); //Every time dequeue() is used, it will print out all the elements currently in the queue.
}

void LinkedQueue::display_queue() //Definition of display_queue() function.
{
    if (empty()) //Checks if the queue is empty.
       {
           cout << "***The queue is now empty.***" << endl; //This sentence is executed if the queue is empty.
           return;
       }

    cout << "Elements inside the queue: " << endl;
    
    CNode* current = C.getCursor(); //If the queue is not empty, a pointer will retrieve the cursor's current position.

    do //Once the cursor is retrieved, the program will complete the actions below.
       {
           cout << C.front() << " "; //Prints the front element in the queue.
           C.advance(); //Once the front element is printed, the cursor will advance.
       }
    
    while (C.getCursor() != current); //This loop will print out the elements in the queue until it goes back the cursor's original position.
    
    cout << endl << endl;
}
