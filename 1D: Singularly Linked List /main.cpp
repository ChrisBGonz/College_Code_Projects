#include <iostream>
#include "Header.h"
#include "cpp.cpp"
#include <string>
using namespace std;

int main()
{
    SLinkedList<string> natoAlphabet; //Creates a list containing words from the NATO Alphabet.
     
     natoAlphabet.insert("Alpha"); //Inserts node with element "Alpha".
     natoAlphabet.insert("Bravo"); //Inserts node with element "Bravo".
     natoAlphabet.insert("Charlie"); //Inserts node with element "Charlie".
     natoAlphabet.insert("Delta"); //Inserts node with element "Delta".
     natoAlphabet.insert("Echo"); //Inserts node with element "Echo".
     natoAlphabet.insert("Foxtrot"); //Inserts node with element "Foxtrot".
     natoAlphabet.insert("Golf"); //Inserts node with element "Golf".
     
     cout << "Elements inside circularly linked list:" << endl;
     natoAlphabet.print(); //Will print the elements provided above.
     
     cout << "\nRemoving elements from the list..." << endl;
     
     natoAlphabet.remove("Alpha"); //Will remove "Alpha" from the list.
     natoAlphabet.remove("Foxtrot"); //Will remove "Foxtrot" from the list.
     natoAlphabet.remove("Delta"); //Will remove "Delta" from the list.
     
     cout << "\nUpdated elements inside singularly linked list:" << endl;
     natoAlphabet.print(); //Prints the updated list.
     
     cout << endl;

    return 0;
}
