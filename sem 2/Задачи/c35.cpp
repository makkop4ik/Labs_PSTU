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
    
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    
    cout << "Максимальное значение элемента:" << max << endl;
    
    
    
    
}
