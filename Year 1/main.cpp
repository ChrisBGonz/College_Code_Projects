#include <iostream>
using namespace std;

int main() 
{
    int n;

    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;
    
    int f[n + 1];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; ++i)
        f[i] = f[i - 1] + f[i - 2];
    
    cout << "Fibonacci Sequence:" << endl;
    
    for (int i = 0; i <= n; ++i)
        cout << f[i] << " ";
    
    cout << endl << endl;
    
    return 0;
}
