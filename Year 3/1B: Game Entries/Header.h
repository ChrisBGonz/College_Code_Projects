#ifndef Header_h
#define Header_h
#include <string>
using namespace std;

class GameEntry //This class will store game score entires.
{
    
public:
    GameEntry(const string& n = "", int s = 0); //Override constructor for parameters name and score.
    
    string getName(); //Get function for a given name.
    int getScore(); //Get function for a given score.
    
private:
    string name; //This will store a players name.
    int score; //This will store a players score.
};


class Scores //This class will store the highest 10 scores.
{
    
public:
    Scores(int maxEnt = 10); //Override constructor sets the max number of entries to 10.
    ~Scores(); //Destructor function for Scores.
    
    void add(GameEntry& e); //Allows for the addition of another game entry.
    
    GameEntry remove(int i) noexcept(false); //Necessary change due to modern version of C++ (C++17).
    
    int getNumEntries() const; //This function will be used to get the number of used entries.
    GameEntry getEntry(int index) const; //This function will get the entries of each GameEntry object.
    void displayHighScores() const;  //Function will display the names and high scores given in GameEntry object parameters.

    
private:
    int maxEntries; //The maximun number of entries allowed (10).
    int numEntries; //The number of entries provided.
    GameEntry* entries; //An array of game entires.
};

#endif
