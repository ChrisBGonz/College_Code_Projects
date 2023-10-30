#include <stdio.h>
#include "Header.h"
#include <iostream>
using namespace std;

template <typename E>
SLinkedList<E>::SLinkedList() //Definition of default constructor.
: head(NULL) { } //Creates a head for the linked list with no elements.

template <typename E>
SLinkedList<E>::~SLinkedList() //Definition of destructor.
{ while (!empty()) removeFront(); } //While loops that deletes nodes until the linked list is empty.

template <typename E>
bool SLinkedList<E>::empty() const //Definition of empty() function.
{ return head == NULL; } //Checks if the linked list is empty.

template <typename E>
const E& SLinkedList<E>::front() const //Definition of front() function.
{ return head -> elem; } //Will return the front element in singularly linked list.

template <typename E>
void SLinkedList<E>::addFront(const E& e) //Definition of addFront() function.
{
    SNode<E>* v = new SNode<E>; //Creates a new node to be added to the front.
    v -> elem = e; //Stores a given element inside the new node.
    v -> next = head; //The head will be the next element after v.
    head = v; //v becomes the new head.
}

template <typename E>
void SLinkedList<E>::removeFront() //Definition of removeFront() function.
{
    SNode<E>* old = head; //Saves the current head.
    head = old -> next; //This line will allow singularly linked list to skip over old head.
    delete old; //Deletes the old head.
}

template <typename E>
void SLinkedList<E>::addBack(const E& e) //Definition of addBack() function.
{
    SNode<E>* new_node = new SNode<E>; //Creates a new node that will be placed in the back.
    new_node -> elem = e; //Places an element inside the new node.
    new_node -> next = NULL; //Sets the new node's next to NULL (making it the tail).

    SNode<E>* current = head; //The current pointer is pointing to the head.
        
    while (current -> next != NULL) //While loop that will move to the back.
        current = current -> next; //The pointer will move to the next node until it reaches the back.
        
        current -> next = new_node; //Links the new node after the original tail.
}

template <typename E>
E SLinkedList<E>::removeBack() //Definition of removeBack() function.
{
    SNode<E>* current = head; //The current pointer is pointing to the head.
    
    while (current -> next -> next != NULL) //While loop that will move to the SECOND last node.
        current = current -> next; //Allows the pointer to travel linked list.

    delete current -> next; //Deletes the last node.
    current -> next = NULL; //Assigns the original second to last node to NULL (making it the new tail).
}

template <typename E>
void SLinkedList<E>::insert(const E& value) //Definition of insert() function.
{
    SNode<E>* new_node = new SNode<E>; //Creates a new node that will store an element.
       new_node -> elem = value; //Element will be stored in the node.

       if (head == NULL || value < head -> elem) //Checks if list is empty OR if the value is the smallest in list.
           addFront(value); //The node will become the front node after the head.
    
       else //If the element to be stored needs to be placed elsewhere.
       {
           SNode<E>* current = head; //Pointer is currently pointing to the head.
           
            while (current -> next != NULL && current -> next -> elem < value) //Traverses list.
                current = current -> next; //Allows pointer to move in list.

            new_node -> next = current -> next; //The new node will be placed after the current.
            current -> next = new_node; //Current node will now point to the new node
        }
}

template <typename E>
void SLinkedList<E>::remove(const E& value) //Definition of remove() function.
{
    if (head == NULL) //Checks if list is empty.
          return; //If list is already empty, there is nothing to remove.

      if (head -> elem == value) //If the head points to an element in the list.
      {
          removeFront(); //This function will be called to remove the node containing element.
          return;
      }
    
    SNode<E>* current = head; //Pointer is currently pointing to the head.
    
    while (current -> next != NULL && current -> next -> elem != value) //Traverses list.
        current = current -> next; //Allows pointer to move in list.

    if (current -> next != NULL) //Ensures the node being accessed is not non-existent.
    {
        SNode<E>* temp = current -> next; //Temporary pointer that points to node that will be removed.
        current -> next = current -> next -> next; //Links out the temporary node.
        delete temp;
    }
}

template <typename E>
void SLinkedList<E>::print() const //Definition of print() function.
{
    SNode<E>* current = head; //Pointer is currently pointing at the head.
    while (current != nullptr) //Loop that will print each element in list.
    {
        cout << current -> elem << " "; //Prints out the current element.
        current = current -> next; //Advances to next node.
    }
    cout << endl;
}
