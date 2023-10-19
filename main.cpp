/*
 This program will obtain 5 integers from the user and calculate and also output their sum at once.
 */
#include <iostream>

using namespace std;

int main()
{
    int a, counter, sum;
    
    sum = 0;
    counter = 1;   //counter initialization
    
    while (counter <= 5)
    {
        cout << "Enter an integer: ";
        cin >> a;
        
        sum = sum + a;
        counter = counter + 1;
    }
    
    cout << "The sum is " << sum << endl;
    
    return 0;
}
