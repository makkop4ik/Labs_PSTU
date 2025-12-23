#include <iostream>
using namespace std;

int main()
{
	int a, N, b, c;
	cin >> N;
	b = 1;
	if (N % 2 == 0 & N>3)
	{
		while (N >= b)
		{
			a = (N - b) / 2;
			while (a != 0)
			{
				cout << " ";
				a = a - 1;
			}

			c = b;
			while (c != 0)
			{
				cout << "*";
				c = c - 1;
			}

			a = (N - b) / 2;
			while (a != 0)
			{
				cout << " ";
				a = a - 1;
			}

			b = b + 2;
			cout << "\n";
		}
	}
	else
	{
		cout << "Введи нечетное число больше 3" << endl;
	}
}