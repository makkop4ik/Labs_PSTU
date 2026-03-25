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
    
    int min = a[0], max = a[0];
    
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        if (min > a[i])
        {
            min = a[i];
        }
    }
        cout << "Максимальный элемент массива: " << max << "\n" << "Минимальный элемент массива: " << min << endl;
    

}