/*
 This program will obtain floating-point numbers from the user and calculate and output their sum. Input should stop if user enters -1.
 */

#include <iostream>
using namespace std;

int main ()
{
    float a, sum;
    
    sum = 0;
    
    cout << "Enter a decimal number: ";
    cin >> a;
    
    while (a != -1)
    {
        sum = sum + a; //This will accumilate the sum
        
        cout << "Enter another decimal (enter -1 to end): ";
        cin >> a;
    }
    
    cout << "The sum is " << sum << endl;
    
    return 0;
}
