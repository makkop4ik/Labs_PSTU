#include <iostream>
using namespace std;

int main()
{
	int N, a, b;
	cin >> N;
	b = N;
	while (b != 0)
	{
		a = N;
		while (a != 0)
		{
			cout << "*";
			a = a - 1;
		}

		b = b - 1;
		cout << "\n";
	}
	return 0;
}