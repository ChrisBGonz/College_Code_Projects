#include <iostream>
#include "Stack.h" //Stack class template definition
using namespace std;

int main() 
{
   Stack<double> doubleStack; //Create a Stack of double
   const size_t doubleStackSize{5}; //Stack size
   double doubleValue{1.1}; //First value to push

   cout << "Pushing elements onto doubleStack\n";

   //Push 5 doubles onto doubleStack
   for (size_t i{0}; i < doubleStackSize; ++i) 
   {
      doubleStack.push(doubleValue);
      cout << doubleValue << ' ';
      doubleValue += 1.1;
   }

   cout << "\n\nPopping elements from doubleStack\n";

   // op elements from doubleStack
   while (!doubleStack.isEmpty()) //Loop while Stack is not empty
   {
      cout << doubleStack.top() << ' '; //Display top element
      doubleStack.pop(); //Remove top element
   }

   cout << "\nStack is empty, cannot pop.\n";

   Stack<int> intStack; //Create a Stack of int
   const size_t intStackSize{10}; //Stack size
   int intValue{1}; //First value to push

   cout << "\nPushing elements onto intStack\n";

   //Push 10 integers onto intStack
   for (size_t i{0}; i < intStackSize; ++i)
   {
      intStack.push(intValue);
      cout << intValue++ << ' ';
   }

   cout << "\n\nPopping elements from intStack\n";

   //Pop elements from intStack
   while (!intStack.isEmpty()) // loop while Stack is not empty
   {
      cout << intStack.top() << ' '; //Display top element
      intStack.pop(); //Remove top element
   }

   cout << "\n\nStack is empty, cannot pop." << endl << endl;
}
