#ifndef header_h
#define header_h

template <typename E>
class ArrayStack //Declaration of class ArrayStack.
{
    enum { DEF_CAPACITY = 100 }; //The array stack will have a max capacity of 100.
    
public: //Public functions for class ArrayStack.
    ArrayStack(int cap = DEF_CAPACITY); //Override constructor that creates a stack with capacity 100.
    int size() const; //Function that will return the number of items inside the stack.
    bool empty() const; //Function that checks if the stack is empty.
    const E& top() const; //Function that retrieves the top item inside stack.
    void push(const E& e); //Function that will "push" items inside stack in FILO order.
    void pop(); //Function that will "pop" items in FILO order.
    void calculateSpan(float price[], int n, int S[]); //Function that will calculate the span.
    
private: //Private data members of class ArrayStack.
    E* S; //The array of stack elements will be accessed by pointer E*.
    int capacity; //The capacity of the stack.
    int t; //This variable will act as an index of the top of the stack.
    
};

#endif
