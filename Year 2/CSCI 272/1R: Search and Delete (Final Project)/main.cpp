//  main.cpp
//  Final Project
//  Created by Christopher Gonzalez on 11/28/22.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userString; //Declare variable userString which will store string entered by the user.
    
    cout << "Enter a string of words: "; //Prompts the user to enter a string of words.
    getline(cin, userString); //Allows the program to retrieve string entered.
    
    /*
     Example Sentence: The purpose by of this program BY is to idenfity byand eliminate any instancesBY in a sentence thbyat contains the characteBYrs "b and y or B and BYY. Additionally, the program by will write theBY modfied sentence backwards.
     */
    cout << "\nOriginal string:\n" << userString << endl; //Outputs the original string entered.
    
    size_t byLocator = userString.find("by"); //Locates the presense of "by" in the string.
    
    while (byLocator != string::npos) //Loop that looks for "by" through entire string.
    {
        userString.erase(byLocator, 2); //Promptly erases "by" in string.
        byLocator = userString.find("by", byLocator); //Allows loop to continue searching.
    }
    
    size_t BYLocator = userString.find("BY"); //Locates the presense of "BY" in the string.
    
    while (BYLocator != string::npos) //Loop that looks for "BY" through entire string.
    {
        userString.erase(BYLocator, 2); //Promptly erases "BY" in string.
        BYLocator = userString.find("BY", BYLocator); //Allows loop to continue searching.
    }
    
    size_t doubleSpaceLocator = userString.find("  ");
    
    while (doubleSpaceLocator != string::npos) //Loop that looks for TWO consecutive empty spaces in string.
    {
        userString.erase(doubleSpaceLocator, 1); //Promptly erases ONE empty space in string.
        doubleSpaceLocator = userString.find("  ", doubleSpaceLocator); //Allows loop to continue searching.
    }
    
    cout << "\nModified string: \n" << userString << endl;
    
    userString = string(userString.rbegin(), userString.rend());
    //Reverses order of text in modified string.
    
    cout << "\nThe modified string written backwards is: \n" << userString << endl << endl;
    
    return 0;
}
