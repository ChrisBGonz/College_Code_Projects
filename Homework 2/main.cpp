#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

int main()
{
    Scores highscores; //Initializes object for class Scores.
    
    GameEntry ge1("John", 99000); //Game entry information for John.
    GameEntry ge2("Alice", 98880); //Game entry information for Alice.
    GameEntry ge3("Marcus", 95950); //Game entry information for Marcus.
    GameEntry ge4("Sophia", 93430); //Game entry information for Sophia.
    GameEntry ge5("Peter", 89310); //Game entry information for Peter.
    GameEntry ge6("Olivia", 87600); //Game entry information for Olivia.
    GameEntry ge7("Vincent", 85740); //Game entry information for Vincent.
    GameEntry ge8("Clara", 85700); //Game entry information for Clara.
    GameEntry ge9("Henry", 83900); //Game entry information for Henry. Note there are only 9 entries.
    
    highscores.add(ge1); //Adds John's information to entries array.
    highscores.add(ge2); //Adds Alice's information to entries array.
    highscores.add(ge3); //Adds Marcus' information to entries array.
    highscores.add(ge4); //Adds Sophia's information to entries array.
    highscores.add(ge5); //Adds Peter's information to entries array.
    highscores.add(ge6); //Adds Olivia's information to entries array.
    highscores.add(ge7); //Adds Vincent's information to entries array.
    highscores.add(ge8); //Adds Clara's information to entries array.
    highscores.add(ge9); //Adds Henry's information to entries array.
    
    cout << "Current highscores:" << endl;
    
    highscores.displayHighScores(); //Displays names and high sores provided.

    
    cout << "Now adding a new entry at the end of array.\n";
    
    GameEntry ge10("JOEY", 81000); //Game entry information for JOEY She will be the 10th entry.
    highscores.add(ge10); //Adds Joey's information to entries array (array is now full with this entry).
    highscores.displayHighScores(); //Displays updates names and high sores with JOEY being at the bottom based on her score.

    
    cout << "Inserting a new entry in the beginning of array.\n";
    
    GameEntry GE1("CHRIS", 100000); //Game entry information for CHRIS. He has the highest score.
    highscores.add(GE1); //Adds CHRIS' information to array (program will add information by insertion sort process).
    highscores.displayHighScores(); //Displays updated information (JOEY's entry is gone given her score is no longer top 10).
    
    cout << "Inserting a new entry in the middle of array.\n";
    
    GameEntry GE5("LUKE", 90000); //Game entry information for LUKE. He will be in the middle.
    highscores.add(GE5); //Adds LUKE'S information by following insertion sort process.
    highscores.displayHighScores(); //Displays updated information (Henry's entry will be gone).
    
    cout << "Attempting to add new entry with a score lower than all entires.\n";
    
    GameEntry GE11("MARY", 75000); //Game entry information for MARY. Her score is not within the top 10.
    highscores.add(GE11); //Will attempt to add MARY's score, but it is too low, so it'll be ignored.
    highscores.displayHighScores(); //Displays information that SHOULD NOT have changed from previous display.
    
    cout << "Removing LUKE from array.\n";
    
    highscores.remove(5); //Will remove LUKE's game entry information.
    highscores.displayHighScores(); //Displays updated information. LUKE is no longer in entries array.

    return 0;
}
