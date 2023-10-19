
/*
 This program will play a game of "guess the number" with the user. The program will generate a random integer number in the range of 1 to 1000.
 
 Created by Christopher Gonzalez on May 23, 2022
*/
 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char y_or_no;
    
    while (y_or_no != 'n')
    {
        int rand_num, x;
    
        srand(time(NULL));
    
        rand_num = rand() % 1000 + 1;
    
        cout << "I have a number between 1 and 1000." << endl;
        cout << "Can you guess the number?" << endl;
        cout << "Please type your first guess:" << endl << endl;
        cin >> x;
    
        while (x != rand_num)
        {
            if (x < rand_num)
            {
                cout << "Too low. Try again." << endl << endl;
                cin >> x;
            }
        
            if (x > rand_num)
            {
                cout << "Too high. Try again." << endl << endl;;
                cin >> x;
            }
        }
    
        cout << "Excellent! You guessed the number!" << endl;
        cout << "Would you like to play again (y or n)?" << endl;
        cin >> y_or_no;
        cout << endl;
    }
        
    return 0;
}
