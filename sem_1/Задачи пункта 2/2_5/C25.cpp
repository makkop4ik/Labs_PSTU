#include <iostream>

using namespace std;
int main()
{
	int N, a, b, c;
	cin >> N;
	b = 0;

	while (N != 0)
	{
		N = N - 1;
		b++;

		a = N;
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

		cout << "\n";
	}
	return 0;
}