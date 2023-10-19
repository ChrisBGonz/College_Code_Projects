#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Tic_Tac_Toe game; //Creates an object called game to play tic-tac-toe.
    
    game.clearBoard(); //Clears the board.
    
    game.putMark(0,0); //Placement of X.
    cout << game << endl;
    
    game.putMark(1,1); //Placement of O.
    cout << game << endl;
  
    game.putMark(0,1); //Placement of X.
    cout << game << endl;
    
    game.putMark(0,2); //Placement of O.
    cout << game << endl;
    
    game.putMark(2,0); //Placement of X.
    cout << game << endl;
   
    game.putMark(1,2); //Placement of O.
    cout << game << endl;
    
    game.putMark(2,2); //Placement of X.
    cout << game << endl;
    
    game.putMark(2,1); //Placement of O.
    cout << game << endl;
    
    game.putMark(1,0); //Placement of X.
    cout << game << endl;
    
    game.getWinner(); //Checks if there is a winner.
    
    if (game.getWinner() == 0) //If there is no winner, it will say "Tie".
        cout << "\nTie" << endl;
    
    else if (game.getWinner() == 1)
        cout << "\n" << game.getWinner() << "(X) Wins" << endl; //If X is the winner, it will print out 1(X).
    
    else if (game.getWinner() == -1)
        cout << "\n" << game.getWinner() << "(O) Wins" << endl; //If O is the winner, it will print out -1(O).
    
    return 0;
}
