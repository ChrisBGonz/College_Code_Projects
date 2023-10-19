#ifndef STACK_H
#define STACK_H
#include <deque>

template<typename T>
class Stack 
{
public:
   //Return the top element of the Stack
   const T& top() {
      return stack.front();
   }

   //Push an element onto the Stack
   void push(const T& pushValue) 
    {
      stack.push_front(pushValue);
    }

   //Pop an element from the stack
   void pop() 
    {
      stack.pop_front();
    }

   //Determine whether Stack is empty
   bool isEmpty() const
    {
      return stack.empty();
    }

   //Return size of Stack
   size_t size() const 
    {
      return stack.size();
    }

private:
   std::deque<T> stack; //Internal representation of the Stack
};

#endif
