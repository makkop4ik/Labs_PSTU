#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n;
    cin >> n;

    
    
    srand(time(0));
    int a[n][n];
    int range_min = 2;
    int range_max = 280000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        a[i][j] = ((double)rand() / RAND_MAX) * (range_max - range_min) +
        range_min;
        cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << "\n";
    
    int mem;
    int j = 0;
    
        for (int i = 0; i < n; i++)
    {
        while(j<n)
        {
            a[i][j] = mem;
    	    a[i][j] = a[j][i];
        	a[j][i] = mem;
            j++;
        }
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        cout << a[i][j] << " ";
        }
    cout << endl;
    
    }
}