#include <iostream>
using namespace std;

int main()
{
	int N, a;
	int b = 0;
	cin >> N;
	while (N != 0)
	{
		cin >> a;
		if (a > 0 && b == 0)
		{
			 b = 1;
		}
		else
		{
			if (a < 0 && b == 0)
			{
				 b = 2;
			}
		}
		N--;
	}

	if (b == 1)
	{
		cout << "Положительное число вводится раньше" << endl;
	}
	else
	{
		if (b == 2)
		{
			cout << "Отрицательное число вводится раньше" << endl;
		}
		else
		{
			cout << "В последовательности только нули" << endl;
		}
	}
}