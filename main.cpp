
#include <iostream>

using namespace std;

void Sum();

int main()
{
    Sum();
    
    return 0;
}

void Sum()
{
    int a, b, c, sum;
    
    cout << "Enter three integers separated by spaces: ";
    cin >> a >> b >> c;
    
    sum = a + b + c;
    
    cout << "The sum is " << sum << endl;
}
