/*
 This program will obtain 5 integers from the user and, using the for command, will determine and output the sum, product, and average.
 */
#include <iostream>
using namespace std;

int main()
{
    int a, sum, product, i;
    float avg;
    
    sum = 0;
    product  = 1;
    
    for (i = 1; i <= 5; i++)
    {
        cout << "Enter an integer: ";
        cin >> a;
        
        sum = sum + a;
        product = product * a;
    }
    
    avg = float(sum) / 5;
    
    cout << "The sum is " << sum << endl;
    cout << "The product is " << product << endl;
    cout << "The average is " << avg << endl;
    
    return 0;
}
