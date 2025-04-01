#include <stdio.h>
#include "Header.h"
#include <iostream>
#include <string>
#include <stdexcept> //This library is needed to use std::out_of_range in C++17.
using namespace std;

GameEntry::GameEntry(const string& n, int s) //Definition of override constructor.
{
    name = n; //Assigns private data member name to n.
    score = s; //Assigns private data member score to s.
}


string GameEntry::getName() //Definition of the getName function.
{
    return name;
}

int GameEntry::getScore() //Definition of the getScore function.
{
    return score;
}

Scores::Scores(int maxEnt) //Dedinition of maxEnt.
{
    maxEntries = maxEnt; //Variable maxEntires will be set to maxEnt (10).
    entries = new GameEntry[maxEntries]; 
    numEntries = 0; //Provides a "default" number of entries.
    
}

Scores::~Scores() //Definition of destructor.
{
    delete[] entries;
}

void Scores::add(GameEntry& e) //This function will add a given score to GameEntry and create ONE extra location if necessary.
{
    int newScore = e.getScore(); //Gets the new score.
    
    if (numEntries == maxEntries) //Checks if numEntries is the same as maxEntries (full).
    {
        if (newScore <= entries[maxEntries - 1].getScore()) //Will ignore newScore if it is less than the 10th highest score.
            return;
    }
    
    else numEntries++; //If newScore > 10th highest score, an extra location will be created to temporarily store newScore.
    
    int i = numEntries - 2; //Variable i will be set to the second to last position in array.
    
    while (i >= 0 && newScore > entries[i].getScore()) //Position will shift to the right while conditions are True.
    {
        entries[i + 1] = entries[i]; //Shifts to the right if newScore is smaller than a given value in entries array.
        i--;
    }
    
    entries[i + 1]= e; //Places e in the correct position.
}

GameEntry Scores::remove(int i) noexcept(false) //Function definition of remove function.
{
    if ((i < 0 || (i > numEntries))) //Checks if there is an invalid index.
        throw std::out_of_range("Invalid index");
 
    GameEntry e = entries[i]; //Temporarily saves the object that will be removed.
    
    for (int j = i +1; j < numEntries; j++) //For loop will shift entries to the left.
       entries[j - 1] =  entries[j]; //Gives previous entry the value of current entry.
       
    numEntries--; //Removes 1 entry.
 
    return e;
}

int Scores::getNumEntries() const //Definition of getNumEntries. Will be used in a for loop parameter to output data.
{
    return numEntries;
}

GameEntry Scores::getEntry(int index) const //Definition of getEntry. Will output names/scores in a for loop.
{
    if (index < 0 || index >= numEntries) //Ensures that tthe index of an entry is within array size.
        throw std::out_of_range("Invalid index");
    
    return entries[index];
}

void Scores::displayHighScores() const  //Definition of display function. Will print name and score of a given entry.
{
    for (int i = 0; i < numEntries; ++i) //Loop will print out no more than the number of entries provided (max of 10 entries).
    {
        GameEntry entry = entries[i];
        cout << entry.getName() << "\t" << entry.getScore() << endl; //Prints name and score.
    }
    
    cout << endl;
}
