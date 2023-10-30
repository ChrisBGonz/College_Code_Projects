#include <stdio.h>
#include "Header.h"
#include <iostream>
using namespace std;

template <typename Elem>
DLinkedList<Elem>::DLinkedList() //Definition of default constructor.
{
    header = new DNode<Elem>; //Creates a header node that will be used in linked list.
    trailer = new DNode<Elem>; //Creates a trailer node that will be used in linked list.
    header -> next = trailer; //Assigns the headers next to the trailer.
    trailer -> prev = header; //Assigns the trailers previous to the header.
}

template <typename Elem>
DLinkedList<Elem>::~DLinkedList() //Definition of the destructor.
{
    while (!empty()) removeFront(); //While loop that removes nodes until the list is empty.
    delete header; //Deletes the header.
    delete trailer; //Deletes the trailer.
}

template <typename Elem>
bool DLinkedList<Elem>::empty() const //Definition of the empty() function.
{ return (header -> next == trailer); } //Checks if the list is empty.

template <typename Elem>
const Elem& DLinkedList<Elem>::front() const //Definition of the front() function.
{ return header -> next -> elem; } //Returns the element after the header.

template <typename Elem>
const Elem& DLinkedList<Elem>::back() const //Definition of the back() function.
{ return trailer -> prev -> elem; } //Returns the element of the node before the tailer.

template <typename Elem>
void DLinkedList<Elem>::add(DNode<Elem>* v, const Elem& e) //Definition of the add() function.
{
    DNode<Elem>* u =  new DNode<Elem>; //Creates a new node to be placed in linked list.
    u -> elem = e; //Stores element e inside the new node.
    u -> next = v; //Links node u before v.
    u -> prev = v -> prev; //Links node u to node that was originally before v.
    u -> prev -> next = v -> prev = u; //Ensures other node links are properly connected to u.
}

template <typename Elem>
void DLinkedList<Elem>::addFront(const Elem& e) //Definition of addFront() function.
{ add(header -> next, e); } //Adds node to the front of the list.

template <typename Elem>
void DLinkedList<Elem>::addBack(const Elem& e) //Definition of addBack() function.
{ add(trailer, e); } //Adds node to the back of the list.

template <typename Elem>
void DLinkedList<Elem>::remove(DNode<Elem>* v) //Definition of remove() function.
{
    DNode<Elem>* u = v -> prev; //Predecessor.
    DNode<Elem>* w = v -> next; //Successor.
    u -> next = w; //Unlinks v from list.
    w -> prev = u; //Unlinks v from list.
    delete v; //Deletes node v.
}

template <typename Elem>
void DLinkedList<Elem>::removeFront() //Definition of removeFront() function.
{ remove(header -> next); } //Removes node from the front.

template <typename Elem>
void DLinkedList<Elem>::removeBack() //Definition of removeBack() function.
{ remove(trailer -> prev); } //Removes node from the back.

template <typename Elem>
void DLinkedList<Elem>::insert(const Elem& e) //Definition of insert() function.
{
    DNode<Elem>* current = header -> next; //Starts from the first node after the header.
    
    while (current != trailer && current -> elem < e) //Loop that will traverse list to insert new element.
        current = current -> next;
    
    DNode<Elem>* newNode = new DNode<Elem>; //Will create a new node to insert the element.
    newNode -> elem = e; //Stores element e inside newNode.
    
    newNode -> next = current; //Will insert the new node before the new node.
    newNode -> prev = current -> prev; //Links nNode's prev to current's prev.
    current -> prev -> next = newNode; //Links current node's previous next to newNode.
    current -> prev = newNode; //Links current's prev to newNode.
}

template <typename Elem>
void DLinkedList<Elem>::remove(const Elem& e) //Definition of remove() function.
{
    DNode<Elem>* current = header -> next; //Starts from the first node after the header.

    while (current != trailer) //Searches for the element to remove.
    {
        if (current -> elem == e) //Checks when the element to be removed is found.
        {
            current -> prev -> next = current -> next; //Skips the current node.
            current -> next -> prev = current -> prev; //Skips the current node, essentially linking out.
            delete current; //Deletes the element.
            return;
        }
        current = current -> next; //Required to successfully print updated list again.
    }
}

template <typename Elem>
void DLinkedList<Elem>::printList() const //Definition of printList() function.
{
    DNode<Elem>* current = header -> next; //Starts from the first node after the header.
    
    while (current != trailer) //Loop that executes each element after header until it reaches trailer.
    {
        cout << current -> elem << " "; //Prints element.
        current = current -> next; //Moves to next element in the list.
    }
    cout << endl;
}
