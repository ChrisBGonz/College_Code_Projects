/*
 This program will initialize a floating point array of size 10 with values obtained from the user. The program will then use a function Smallest that accepts the array and it's size and returns the smalles array element.
 */
#include <iostream>

using namespace std;

float Smallest(float [], int);
int main()
{
    const int size = 10;
    float a [size], min;
    
    for (int i =  0; i < size; i++)
    {
        cout << "Enter a decimal number: ";
        cin >> a [i];
    }
    
    min = Smallest(a, size);
    
    cout << "The smallest array element is " << min << endl;
    
    return 0;
}

float Smallest (float b[], int s)
{
    float smallest = b[0];
    
    for (int i = 0; i < s; i++)
    {
        if (b[i] < smallest)
            smallest = b[i];
    }
    
    return smallest;
}
