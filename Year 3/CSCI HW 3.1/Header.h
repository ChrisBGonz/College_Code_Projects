#ifndef Header_h
#define Header_h

template <typename E>
class SLinkedList; //This forward declaration is essential so for the friend class declaration work.

template <typename E>
class SNode //Declaration of class SNode, which creates a node for singularly linked list.
{
private: //Private data members for class SNode.
    E elem; //This variable will store a given element inside node.
    SNode<E>* next; //This pointer will point to the next item in singularly linked list.
    friend class SLinkedList<E>; //Grants class SLinkedList access to private data members.
};

template <typename E>
class SLinkedList //Declaration of class SLinkedList, which creates the singularly linked list.
{
public: //Public functions to be used.
    SLinkedList(); //Default constructor.
    ~SLinkedList(); //Destructor.
    bool empty() const; //Function that will checks if linked list is empty.
    const E& front() const; //Function that returns the front element of linked list.
    void addFront(const E& e); //Function that adds node to the front of linked list.
    void removeFront(); //Function that removes the front node from the list.
    void addBack(const E& e); //Function that will add a node to the back of the list.
    E removeBack(); //Function that will remove the node in the back.
    void insert(const E& value); //Function that will inset element in a given node.
    void remove(const E& value); //Function that will remove element in a given node.
    void print() const; //Declaration of a print function.
    
private: //Private data members of class SLinkedList.
    SNode<E>* head; //The head of the list.
};

#endif
