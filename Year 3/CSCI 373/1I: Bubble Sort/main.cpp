#include <iostream>
#include "header.h"
using namespace std;

void bubbleSort1(NodeSequence& S) //This function will conduct bubble sort using the index.
{
    int n = S.size(); //Gets the size of the list.
    for (int i = 0; i < n; i++) //This loop will allow for traversal of the list.
    {
        for (int j = 1; j < n - i; j++) //This loop will allow for element comparisons.
        {
            NodeSequence::Iterator prec = S.atIndex(j - 1); //The predecessor.
            NodeSequence::Iterator succ =  S.atIndex(j); //The successor.
            
            if (*prec > *succ) //If this condition is true, prec and succ will be swapped.
            {
                int tmp = *prec; //Creates a temporary copy of the predecessor.
                *prec = *succ; //The value of the predecessor becomes the successor value.
                *succ = tmp; //The value of the successor becomes the temporary value.
            }
        }
    }
}

void bubbleSort2(NodeSequence& S) //This function will conduct bubble sort using the position.
{
   int n = S.size(); //Gets the size of the list.
   for (int i = 0; i < n; i++) //This loop will allow for traversal of the list.
   {
       NodeSequence::Iterator prec = S.begin(); //The predecessor is assigned to the beginning position.
       for (int j = 1; j < n - i; j++) //This loop will allow for element comparisons.
       {
           NodeSequence::Iterator succ = prec; //Initializes the successor to the predecessor.
           ++succ; //Assigns the successor to the element after the predecessor.
           if (*prec > * succ) //If this condition is true, prec and succ will be swapped.
           {
               int tmp = *prec; //Creates a temporary copy of the predecessor.
               *prec = *succ; //The value of the predecessor becomes the successor value.
               *succ = tmp; //The value of the successor becomes the temporary value.
           }
           ++prec; //Advances to the next node.
       }
   }
}

int main()
{
    NodeSequence sequence; //This sequence will test function bubbleSort1;
    
    cout << "Inserting elements to test Bubble Sort 1 function..." << endl;
    
    sequence.insertBack(3); //Insert element 3 at the back of the list.
    sequence.insertBack(1); //Insert element 1 at the back of the list.
    sequence.insertBack(5); //Insert element 5 at the back of the list.
    sequence.insertBack(2); //Insert element 2 at the back of the list.
    sequence.insertBack(4); //Insert element 4 at the back of the list.
    
    cout << "Before Bubble Sort 1 function: ";
    
    for (auto it = sequence.begin(); it != sequence.end(); ++it)
            cout << *it << " "; //The loop will print the elements in the order they were inserted.
    
        cout << endl;
    
    bubbleSort1(sequence); //Calls function bubbleSort1 to sort the elements in value order.
    
    cout << "After Bubble Sort 1 function: ";
        for (auto it = sequence.begin(); it != sequence.end(); ++it)
            cout << *it << " "; //Prints the updated order of the elements.
    
        cout << endl << endl;
    
    NodeSequence sequence2; //This sequence will test the second function bubbleSort2;
    
    cout << "Inserting new elements to test Bubble Sort 2 function..." << endl;
    
    sequence2.insertBack(8); //Insert element 8 at the back of the list.
    sequence2.insertBack(10); //Insert element 10 at the back of the list.
    sequence2.insertBack(6); //Insert element 6 at the back of the list.
    sequence2.insertBack(9); //Insert element 9 at the back of the list.
    sequence2.insertBack(7); //Insert element 7 at the back of the list.
    
    cout << "Before Bubble Sort 2 function: ";
    
    for (auto it = sequence2.begin(); it != sequence2.end(); ++it)
            cout << *it << " "; //The loop will print the elements in the order they were inserted.
    
        cout << endl;
    
    bubbleSort2(sequence2); //Calls function bubbleSort2 to sort the elements.
    
    cout << "After Bubble Sort 2 function: ";
        for (auto it = sequence2.begin(); it != sequence2.end(); ++it)
            cout << *it << " "; //Prints the updated order of the elements.
    
    cout << endl << endl;
    
    return 0;
}
