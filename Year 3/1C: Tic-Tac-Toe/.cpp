#include <stdio.h>
#include "Header.h"
#include <iostream>
using namespace std;

void Tic_Tac_Toe::clearBoard() //Function definition of clearBoard().
{
    for (int i = 0; i < 3; i++) //For loop that represents the x coordinate of playing board.
    {
        for (int j = 0; j < 3; j++) //For loop that represents the y coordinate of playing board.
            board[i][j] = EMPTY; //Clears the board from coordinates (0,0) to (2,2).
        
        currentPlayer = X; //Ensures that X goes first before the game starts.
    }
}

void Tic_Tac_Toe::putMark(int i, int j) //Function definition of putMark(int i, int j).
{
    board[i][j] = currentPlayer; //Places X or O on the coordinates that the player chooses (starting with X).
    currentPlayer = -currentPlayer; //Once the current player places their game piece, the next player begins their turn.
}

bool Tic_Tac_Toe::isWin(int mark) //Function definition for isWin(int mark)
{
    int win = 3 * mark;
    
    return ((board[0][0] + board[0][1] + board[0][2] == win) //Win combination.
            || (board[1][0] + board[1][1] + board[1][2] == win) //Win combination.
            || (board[2][0] + board[2][1] + board[2][2] == win) //Win combination.
            || (board[0][0] + board[1][0] + board[2][0] == win) //Win combination.
            || (board[0][0] + board[1][1] + board[2][1] == win) //Win combination.
            || (board[0][2] + board[1][2] + board[2][2] == win) //Win combination.
            || (board[0][0] + board[1][1] + board[2][2] == win) //Win combination.
            || (board[2][0] + board[1][1] + board[0][2] == win)); //Win combination.
}

int Tic_Tac_Toe::getWinner() //Function definition of getWinner().
{
    if (isWin(X)) //If X is the winner, it returns X (1).
        return X;
    
    else if (isWin(O)) //If O is the winner, it returns O (-1).
        return O;
    
    else //If there is no winner, it returns EMPTY (0).
        return EMPTY;
}

void Tic_Tac_Toe::printBoard() const //Function definition of printBoard()
{
    for (int i = 0; i < 3; i++) //The horizontal axis of the board.
    {
        for (int j = 0; j < 3; j++) //The vertical axis of the board.
        {
            switch (board[i][j]) //Allows for alternation of board pieces to be printed based on coordinates of piece.
            {
                case 1: //Prints X when putMark(int i, int j) function is used for this piece.
                    cout << "X";
                    break;
                    
                case  -1: //Prints O when putMark(int i, int j) function is used for this piece.
                    cout << "O";
                    break;
                    
                case 0:
                    cout << " "; //Prints Nothing when X or O is not put down in specified coorinate.
                    break;
            }

            if (j < 2) //Creates vertical lines used in tic-tac-toe playing board.
                cout << "|";
        }

        if (i < 2) //Creates horizonzal lines used in tic-tac-toe playing board.
            cout << "\n-+-+-\n";
    }

}

ostream& operator<<(ostream& os, const Tic_Tac_Toe& game) //Function definition for overload operator.
{
    game.printBoard(); //Uses printBoard() function to print the board.
    os << endl;
    return os;
}
