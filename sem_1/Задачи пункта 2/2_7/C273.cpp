#include <iostream>

using namespace std;

int main()
{
	int N, a, b;
	cin >> N;
	a = N;
	b = N;
	if (N >= 3)
	{
		while (a != 0)
		{
			if (a == 1 or a == N)
			{
				while (b != 0)
				{
					cout << "*";
					b = b - 1;
				}
			}
			else
			{
				cout << "*";
				while (b != 2)
				{
					cout << " ";
					b = b - 1;
				}
				cout << "*";
			}
			a = a - 1;
			b = N;
			cout << "\n";
		}
	}
	else
	{
		cout << "число должно быть равно 3 или больше" << endl;
	}
}