#include <stdio.h>
#include "header.h"

NodeList::Iterator::Iterator(Node* u) //Function definition of the Iterator constructor.
{ v = u; } //Initializes variable v to variable u.

Elem& NodeList::Iterator::operator*() //Function definition of operator*().
{ return v -> elem; } //Returns a reference to the element.

bool NodeList::Iterator::operator==(const Iterator& p) const //Function definition of bool operator (true).
{ return v == p.v; } //Compares the position of p and v and returns true if v = p.v

bool NodeList::Iterator::operator!=(const Iterator& p) const //Function definition of bool operator (false).
{ return v != p.v; } //Compares the position of p and v and returns false if v != p.v

NodeList::Iterator& NodeList::Iterator::operator++() //Function definition of operator++().
{
    v = v -> next; //Advances to the next position in the list.
    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--() //Function definition of operator--().
{
    v = v -> prev; //Advances to the previous position in the list.
    return *this;
}

NodeList::NodeList() //Function definition of NodeList constructor.
{
    n = 0; //The number of elements is initially set to 0 (the list is empty).
    header = new Node; //Creates a header node.
    trailer = new Node; //Creates a trailer node.
    header -> next = trailer; //Assigns the headers next to the trailer.
    trailer -> prev = header; //Assigns the trailers previous to the header.
}

int NodeList::size() const //Function definition of size().
{ return n; } //Returns the number of elements in size the list.

bool NodeList::empty() const //Function definition of empty().
{ return (n == 0); } //If n = 0, there are no elements in the list, therefore the list is empty.

NodeList::Iterator NodeList::begin() const //Function definition of begin().
{ return Iterator(header -> next); } //The beginning position is the first item after the header.

NodeList::Iterator NodeList::end() const //Function definition of end().
{ return Iterator(trailer); } //The ending position is the trailer.

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) //Function definition of insert().
{
    Node* w = p.v; //Pointer w will point to p's node.
    Node* u = w -> prev; //Pointer u will point to the node before p.
    Node* v = new Node; //Creates a new node to insert in the list.
    v -> elem = e; //Stores element e inside new node.
    v -> next = w; //Links in v by setting v's next to w.
    w -> prev = v; //Links in v by setting w's previous to v.
    v -> prev = u; //Links in v by setting v's previous to u.
    u -> next = v; //Links in v by setting u's next to v.
    n++; //The total number of items in the list is increased by 1.
}

void NodeList::insertFront(const Elem &e) //Function definition of insertFront().
{ insert(begin(), e); } //Uses begin() function to insert element e at the front of the list.

void NodeList::insertBack(const Elem &e) //Function definition of insertBack().
{ insert(end(), e); } //Uses end() function to insert element e at the end of the list.

void NodeList::erase(const Iterator &p) //Function definition of erase().
{
    Node* v = p.v; //Identifies the node to be removed.
    Node* w = v -> next; //The successor of v.
    Node* u = v -> prev; //The predecessor of v.
    u -> next = w; //Unlinks v by setting u's next to w.
    w -> prev = u; //Unlinks v by setting w's previous to u.
    n--; //The total number of items in the list is decreased by 1.
}

void NodeList::eraseFront() //Function definition of eraseFront().
{ erase(begin()); } //Uses begin() function to erase element e at the front of the list.

void NodeList::eraseBack() //Function definition of eraseBack().
{ erase(--end()); } //Uses end() function to erase element e at the end of the list.

NodeSequence::Iterator NodeSequence::atIndex(int i) const //Function definition of atIndex().
{
    Iterator p = begin(); //Sets position p at the first element using begin().
    for (int j = 0; j < i; j++) //For loop that will get the position.
        ++p; //The position will increment by 1 until j = i.
    
    return p; //Returns the position value.
}

int NodeSequence::indexOf(const Iterator& p) const //Function definition of indexOf().
{
    Iterator q = begin(); //Sets position q at the first element using begin().
    int j = 0; //Will track the number of advancements (hops) needed to create index for p.
    while (q != p) //Loop that will advance until q = p.
    {
        ++q; //Advances position.
        ++j; //Count the number of hops needed until p is reached.
    }
    return j; //Returns the index value.
}
