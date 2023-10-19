
#include <iostream>

using namespace std;

int Cube(int);
int main()
{
    int x, cube;
    
    x = 3;
    cube = Cube(x);
    
    cout << "The cube of " << x << " is " << cube << endl;
    
    return 0;
}

int Cube(int a)
{
    return a * a * a;
}
