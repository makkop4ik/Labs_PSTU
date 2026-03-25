#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    
    
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
    
    if(k > n)
    {
        k = k%n;
    }
    
    int b[n];
    for (int i = 0; i < n; i++)
    {
        if(i + 1 <= k)
        {
            b[n - k] = a[i];
        }
        else
        {
            b[i - k] = a[i];
        }
    }
    
    cout << "конечная матрица:" << endl;
    
       for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    
    
    
}
