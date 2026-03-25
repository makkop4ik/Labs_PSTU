#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ChangeStr(int a[5][5], int n, int str1, int str2)
{
	int mem;
	str1--;
	str2--;
	for (int i = 0; i < n; i++)
	{
		mem = a[str1][i];
		a[str1][i] = a[str2][i];
		a[str2][i] = mem;
	}
}

int main()
{
	srand(time(0));
	int m = 5, n = 5; 
	int a[5][5];       

	int range_min = 2;
	int range_max = 280000;

	cout << "Исходная матрица:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j][2] > a[j + 1][2])
			{
				ChangeStr(a, n, j + 1, j + 2); 
			}
		}
	}

	cout << "Получившаяся матрица:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}