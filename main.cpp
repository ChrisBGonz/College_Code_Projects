
#include <iostream>

using namespace std;

float Average(int [], int);
int main()
{
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    float avg;
    
    avg = Average(a, 10);
    
    cout << avg << endl;
    
    return 0;
}

float Average(int x[], int size)
{
    int sum = 0;
    float average;
    
    for (int i = 0; i <= size; i++)
        sum = sum + x[i];
    
    average = float(sum) / size;
    
    return average;
}
