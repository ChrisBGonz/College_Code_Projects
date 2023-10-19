#include <iostream>

using namespace std;

bool Is_Even(int);
int main()
{
    int x;
    bool result;
    
    for (int i = 1; i <= 10; i++)
    {
        cout << "Enter an integer: ";
        cin >> x;
        
        result = Is_Even(x);
        
        if (result == true)
            cout << x << " is even." << endl;
        
        else
            cout << x << " is odd." << endl;
    }
    return 0;
}

bool Is_Even(int a)
{
    if (a % 2 == 0)
        return true;
    
    else
        return false;
}
