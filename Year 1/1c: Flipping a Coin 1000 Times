#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int toss, h_count, t_count;
    
    h_count = 0;
    t_count = 0;
    
    srand(time(NULL));

    for (int i = 1; i <= 1000; i++)
    {
        toss = rand() % 2;
        
        if (toss == 1)
            h_count++;
        
        else
            t_count++;
    }
    
    cout << "Heads: " << h_count << endl;
    cout << "Tails: " << t_count << endl;
    
    return 0;
}
