#ifndef header_h
#define header_h
#include <string>
using namespace std;

/*
 This program will use a circularly linked list to create a queue. In order to do this, we must provide code for the queue AND the circularly linked list.
 */

typedef string Elem;
class CNode //Declared class CNnode which will create nodes for circularly linked list.
{
public:
    CNode* getNext() const;
    const Elem& getElement() const;
    
private: //Private data members.
    Elem elem; //The element (song name) that will be stored in a node.
    CNode* next; //The next item in the list.
    
    friend class CircleList; //Grants class CricleList access to private data members.
};

class CircleList //Declaration of class CircleList which will create circularly linked list.
{
public: //Public functions that will be used.
    CircleList(); //Default constructor.
    ~CircleList(); //Destructor.
    bool empty() const; //Function that will check if linked list is empty.
    const Elem& front() const; //Function that will get the element after the cursor.
    const Elem& back() const; //Function that will get the element at the cursor.
    void advance(); //Function that will advance cursor in linked list.
    void add(const Elem& e); //Function that will add a node after cursor.
    void remove(); //Function that will remove the node after cursor.
    CNode* getCursor() const; //Function that will get the cursor.
    
private:
    CNode* cursor; //The cursor.
};

typedef string Elem;
class LinkedQueue //Declared class LinkedQueue.
{
public: //Public functions for class LinkedQueue.
    LinkedQueue(); //Default constructor.
    int size() const; //Function that will return the number of items inside the queue.
    bool empty() const; //Function that checks if the queue is empty.
    const Elem& front() const; //Function that will retrieve the front element in queue.
    void enqueue(const Elem& e); //Function that will insert items at the front.
    void dequeue(); //Function that will remove items at the front.
    void display_queue(); //Function that will print ALL contents in queue.

private: //Private data members of class LinkedQueue.
    CircleList C; //The items that will be stored in queue.
    int n; //The number of items in the queue.
};

#endif
