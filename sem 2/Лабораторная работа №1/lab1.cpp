#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int a[50];
    int range_min = 2;
    int range_max = 280000;
    for (int i = 0; i < 50; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) +
        range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    
    int i = 0;
    bool flag = false;
    
    while (i < 50 and flag == false)
    {
        if(a[i] == 0)
        {
            flag = true;
            a[i] = a[i + 1];
        }
        i++;
    }
    
    while (i < 49)
    {
        a[i] = a[i + 1];
        i++;
    }
    
    

        int S = 75;
        int b[75];

    
    
    i = 0;
    int j = 0;
    
    
    while (i + j < S)
    {
        if (i%2 == 1)
        {
            b[i + j] = a[i];
            j++;
            b[i+j] = a[i - 1] + 2;
        }
        else
        {
            b[i + j] = a[i];
        }
        i++;
    }
    
    i = 0;
    while(i < S)
    {
        cout << b[i] << " ";
        i++;
    }
    cout<< endl;
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

}