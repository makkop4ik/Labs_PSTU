#include <iostream>

using namespace std;
int main()
{
	int N, a, b;
	cin >> N;
	b = 0;

	while (N != 0)
	{
		N = N - 1;
		b++;

		a = N;
		while (a != 0)
		{
			cout << "*";
			a = a - 1;
		}


		cout << "\n";
	}
	return 0;
}