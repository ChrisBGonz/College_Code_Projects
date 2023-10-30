#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

int main()
{
    CircleList playList; //Creates object playList to add songs.
    playList.add("The Resistance"); //Adds the song to the cirularly linked list.
    playList.add("Darkness Before The Dawn"); //Adds the song to the cirularly linked list.
    playList.add("Undefeatable"); //Adds the song to the cirularly linked list.
    playList.add("I Want to Live"); //Adds the song to the cirularly linked list.
    playList.add("Find Your Flame"); //Adds the song to the cirularly linked list.
    playList.add("Hero"); //Adds the song to the cirularly linked list.
    playList.add("Rise"); //Adds the song to the cirularly linked list.
    playList.add("Am I Dreaming"); //Adds the song to the cirularly linked list.
    
    /*
     Note: The front() function will return the element referenced by the cursor, which will be the last song that was added. The playlist will play the songs in the order of the most recent song added to oldest song in playlist.
    */
    
    for (int i =  1; i <= 3; i++) //Loop that will go through entire playlist 3 times.
    {
        for (int j = 1; j <= 8; j++) //Loop that will print each song.
        {
            cout << "Now Playing: " << playList.front() << endl; //Will list the current song.
            
            playList.advance(); //Moves the cursor to the next node (next song).
        }
        
        cout << endl;
    }

    return 0;
}
