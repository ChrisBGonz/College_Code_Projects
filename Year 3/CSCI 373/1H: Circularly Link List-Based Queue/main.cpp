#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main()
{
    LinkedQueue myQueue; //Creates a queue to store elements.
    
    myQueue.enqueue("One"); //Stores and prints the first element "One".
    myQueue.enqueue("Two"); //Stores the first element "Two" and prints all elements in queue.
    myQueue.enqueue("Three"); //Stores the first element "Three" and prints all elements in queue.
    myQueue.enqueue("Four"); //Stores the first element "Four" and prints all elements in queue.
    myQueue.enqueue("Five"); //Stores the first element "Five" and prints all elements in queue.
    
    cout << "***Removing elements from the queue one at a time***" << endl << endl;
    
    myQueue.dequeue(); //Remove's the front element inserted in the queue (One).
    myQueue.dequeue(); //Remove's the front element inserted in the queue (Two).
    myQueue.dequeue(); //Remove's the front element inserted in the queue (Three).
    myQueue.dequeue(); //Remove's the front element inserted in the queue (Four).
    myQueue.dequeue(); //Remove's the last element inserted in the queue (Five).
    
    cout << endl;
    
    return 0;
}
