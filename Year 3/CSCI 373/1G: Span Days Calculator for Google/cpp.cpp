#include <stdio.h>
#include "header.h"
#include <iostream>
#include <stdexcept> //This library is needed to use std::runtime_error() function.
using namespace std;

template <typename E>
ArrayStack<E>::ArrayStack(int cap) //Definition of override constructor.
: S(new E[cap]), capacity(cap), t(-1) { } //Creates an array stack with default capacity and index.

template <typename E>
int ArrayStack<E>::size() const //Definition of size() function.
{ return (t + 1); } //Returns the total number of items inside stack.

template <typename E>
bool ArrayStack<E>::empty() const //Definition of empty() function.
{ return (t < 0); } //Checks if the stack is empty.

template <typename E>
const E& ArrayStack<E>::top() const //Definition of top() function.
{
    if (empty()) //Uses empty() function to see if there is an item to use top() function.
        throw std::runtime_error("The stack is empty, unable to use top function."); //Exception handling.
    
    return S[t]; //If stack is not empty, the program returns the top item.
}

template <typename E>
void ArrayStack<E>::push(const E &e) //Definition of push() function.
{
    if (size() == capacity) //Checks if stack if full using size() function and capacity value.
        throw std::runtime_error("The stack is full, unable to push."); //Exception handling.
    
    S[++t] = e; //If stack is not full, the program will push item into stack.
}

template <typename E>
void ArrayStack<E>::pop() //Definition of pop() function.
{
    if (empty()) //Uses empty() function to see if there is an item to use pop() function.
        throw std::runtime_error("Unable to pop from a empty stack."); //Exception handling.
    
    --t; //If stack is not empty, it pops the top item in stack.
}

template <typename E>
void ArrayStack<E>::calculateSpan(float price[], int n, int S[]) //Function definition of calculateSpan().
{
    
    ArrayStack<int> st; //Creates another stack that will be used for calculations.
    st.push(0); //Pushes index of first element into stack.
    
    S[0] = 1; //The span value for the first element should always have a value of 1.
    
    for (int i = 1; i < n; i++) //Loop that will calculate the span for the rest of the elements.
    {
        while (!st.empty() && price[st.top()] <= price[i]) //Will pop elements on top of stack while both conditions are true.
            st.pop(); //Pops the element on top of stack.
        
        S[i] = (st.empty())? (i + 1) : (i - st.top()); //Stores the span calculated.
        
        st.push(i); //Pushes the element into the stack.
    }
    
}
