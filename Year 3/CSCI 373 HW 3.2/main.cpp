#include <iostream>
#include "Header.h"
#include "cpp.cpp"
using namespace std;

int main()
{
    DLinkedList<int> myList; //Creates doubly linked list called myList (accepts integers).
    
    myList.insert(5); //Inserts element 5 in list.
    myList.insert(3); //Inserts element 3 in list.
    myList.insert(8); //Inserts element 8 in list.
    myList.insert(9); //Inserts element 9 in list.
    myList.insert(1); //Inserts element 1 in list.
    myList.insert(7); //Inserts element 7 in list.
    myList.insert(2); //Inserts element 2 in list.
    myList.insert(10); //Inserts element 10 in list.
    myList.insert(4); //Inserts element 4 in list.
    myList.insert(6); //Inserts element 6 in list.
    
    //The list will be sorted in numerical order based on definition of insert() function.
    
    cout << "Elements inside doubly linked list:" << endl;
    myList.printList(); //Prints the list (sorted).
    
    cout << "\nRemoving elements from the list..." << endl;
    myList.remove(9); //Removes (deletes) element 9 in list.
    myList.remove(5); //Removes (deletes) element 5 in list.
    myList.remove(10); //Removes (deletes) element 10 in list.
    
    cout << "\nUpdated elements inside doubly linked list:" << endl;
    myList.printList(); //Prints the updated list.
    
    cout << endl;
    
    return 0;
}
