/*
 This program will obtain integers from the user and calculate and output their sum, product, and average. The program needs to stop when the user enters 999.
 */

#include <iostream>
using namespace std;

int main ()
{
    int x, sum, product, count;
    float avg;
    
    sum = 0;
    product = 1;
    count = 0;
    
    cout << "Enter an integer: ";
    cin >> x;
    
    while (x!= 999)
    {
        sum = sum + x;
        product = product * x;
        count = count + 1;
        
        cout << "Enter another integer (enter 999 to end): ";
        cin >> x;
    }
    
    avg = float (sum) / count;
    
    cout << "The sum is " << sum << endl;
    cout << "The product is " << product << endl;
    cout << "The average is " << avg << endl;
    
    return 0;
}
