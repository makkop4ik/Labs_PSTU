#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N, a, b;
	cin >> N;
	a = sqrt(N);
	b = a;
	if (N >= 4)
	{
		while (b != 0)
		{
			while (a != 0)
			{
				cout << "*";
				a = a - 1;
			}
			b = b - 1;
			a = sqrt(N);
			cout << "\n";
		}
	}
	else
	{
		cout << "Кажется, тебе нужно взять другое число" << endl;
	}
}