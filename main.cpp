/*
 This program will use a for loop and obtain five integers from the user and determine if each integer is a multiple of 5.
 */

# include <iostream>

using namespace std;

int main()
{
    int i, a;
    
    cout << "Enter five integers separated by spaces: ";
    
    for (i = 1; i <= 5; i++)
    {
        cin >> a;
        
        if (a % 5 == 0)
            cout << a << " is a multiple of 5" << endl << endl;
        
        else
            cout << a << " is not a multiple of 5" << endl << endl;
    }
    
    return 0;
}
