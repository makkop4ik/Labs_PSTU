#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    
    srand(time(0));
    int a[n];
    int range_min = 2;
    int range_max = 280000;
    for (int i = 0; i < n; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) +
        range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    
    int memory;
    for(int i = 0; i < n/2; i++)
    {
        memory = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = memory;

    }
    
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<< endl;
}
    
