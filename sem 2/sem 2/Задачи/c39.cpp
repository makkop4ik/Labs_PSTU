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
    
    int b[n/2];
    int j = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 1)
        {
            b[j] = a[i];
            j++;
        }

    }
    for (int i = 0;i < n/2; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    
}
   