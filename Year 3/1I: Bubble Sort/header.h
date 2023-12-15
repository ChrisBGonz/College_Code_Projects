#ifndef header_h
#define header_h

/*
 This program will conduct the bubble sort algorithm in two different ways with the use of iterators, a list abstract data type, and a sequence abstract data type.
 */

typedef int Elem; //This bubble sort algorithm will work with integer numbers.
class NodeList //Elements will be preserved in a (doubly linked) list.
{
private: //This section will declare struct Node that is needed for a list ADT.
    struct Node //The individual nodes that will be used in the list.
    {
        Elem elem; //Element value that will be stored.
        Node* prev; //A pointer that will point to the previous node in the list.
        Node* next; //A pointer that will point to the next node in the list.
    };
    
public: //This section will declare the use of iterators in the form of a class.
    class Iterator //Class Iterator declaration.
    {
    public: //Functions of class Iterator.
        Elem& operator*(); //Provides a reference to a given element.
        bool operator == (const Iterator& p) const; //Will compare positions in the list (checks for true).
        bool operator != (const Iterator& p) const; //Will compare positions in the list (checks for false).
        Iterator& operator++(); //Function that moves to the next position in the list.
        Iterator& operator--(); //Function that moves to the previous position in the list.
        friend class NodeList; //Grants class NodeList access to the following private members.
        
    private: //Variables that can only be accessed by class Iterator (and friends).
        Node* v; //Pointer to a node.
        Iterator(Node* u); //Allows for construction of iterators from the node.
    };
    
public: //Functions for class NodeList.
    NodeList(); //Default constructor.
    int size() const; //Function that will get the size of the list.
    bool empty() const; //Will check if the list is empty.
    Iterator begin() const; //The beginning position of the list.
    Iterator end() const; //The end position just beyond the last node containing an element.
    void insert(const Iterator& p, const Elem& e); //Will insert elements BEFORE position p.
    void insertFront(const Elem& e); //Insert elements at the front of the list.
    void insertBack(const Elem& e);  //Insert elements at the back of the list.
    void erase(const Iterator& p); //Removes elements from the list.
    void eraseFront(); //Removes the first element in the list.
    void eraseBack(); //Removes the last element in the list.
    
private: //Private data members of class NodeList.
    int n; //The number of elements in the list.
    Node* header; //Since we are using a (doubly linked) list, a header pointer is needed.
    Node* trailer; //Since we are using a (doubly linked) list, a trailer pointer is needed.
};


class NodeSequence : public NodeList
//A sequence is needed for the bubble sort algorithm. The sequence also has access to NodeList functions.
{
public: //Public functions of class NodeSequence
    Iterator atIndex(int i) const; //Will get the position from the index.
    int indexOf(const Iterator& p) const; //Will get the index from the position.
};

#endif
