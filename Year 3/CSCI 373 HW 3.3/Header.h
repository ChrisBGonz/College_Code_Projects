#ifndef Header_h
#define Header_h
#include <string>
using namespace std;

typedef string Elem;
class CNode //Declared class CNnode which will create nodes for circularly linked list.
{
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
    
private:
    CNode* cursor; //The cursor.
};

#endif
