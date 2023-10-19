#ifndef Header_h
#define Header_h
#include <iostream>
using namespace std;

class Tic_Tac_Toe //Class declaration Tic_Tac_Toe
{
    
public: //Functions that are needed for game.
    void clearBoard(); //Will ensure the "gameboard" is clear before playing.
    void putMark(int i, int j); //Places X and O on the gameboard.
    bool isWin(int mark); //Will check if there is a winning combination for X or O.
    int getWinner(); //Will retrieve the winning player.
    void printBoard() const; //Prints the board.
    
    const int X = 1; //The value for the X piece. Value will be used in isWin(int mark) function.
    const int O = -1; //The value for the X piece. Value will be used in isWin(int mark) function.
    const int EMPTY = 0; //Value will be used in clearBoard() and isWin(int mark) function if there is no winner.
    
    friend ostream& operator<<(ostream& os, const Tic_Tac_Toe& game); //Overload operator function.
    
private: //Private data members.

    int board[3][3]; //The demensions of the board.
    int currentPlayer; //The person that is playing (X or O).
};

#endif
