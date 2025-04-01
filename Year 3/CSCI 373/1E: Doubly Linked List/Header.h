#ifndef Header_h
#define Header_h

template <typename Elem>
class DLinkedList; // Forward declaration of DLinkedList

template <typename Elem>
class DNode //Declaration of class DNode, which creates a node for doubly linked list.
{
private: //Private data members.
    Elem elem; //This variable will store given element inside node.
    DNode* prev; //Pointer that will point to the previous node in list.
    DNode* next; //Pointer that will point to the next node in list.
    friend class DLinkedList<Elem>; //Provides class DLinkedList access to private data members.
};

template <typename Elem>
class DLinkedList //Declaration of class DLinkedList, which will create Doubly Linked List.
{
public: //Public functions that will be used.
    DLinkedList(); //Default constructor.
    ~DLinkedList(); //Destructor.
    bool empty() const; //Function that will checks if linked list is empty.
    const Elem& front() const; //Function that returns the front element of linked list.
    const Elem& back() const; //Function that returns the back element of linked list.
    void addFront(const Elem& e); //Function that adds node to the front of linked list.
    void addBack(const Elem& e); //Function that adds node to the back of linked list.
    void removeFront(); //Function that removes the front node from the list.
    void removeBack(); //Function that removes the back node from the list.
    void insert(const Elem& e); // Function that inserts element in node.
    void remove(const Elem& e); // Function that removes (deletes) element in node.
    void printList() const; //Function that will print the doubly linked list.

private: //Private data members of class DLinkedList.
    DNode<Elem>* header; //The header pointer.
    DNode<Elem>* trailer; //The trailer pointer.
    
protected: //Functions that can be called within class.
    void add(DNode<Elem>* v, const Elem& e); //Function that will insert a new node before v.
    void remove(DNode<Elem>* v); //Function that will remove node v.
};

#endif
