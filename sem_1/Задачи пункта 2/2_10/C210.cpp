#include <iostream>
using namespace std;

int main()
{
	int N, a, max;
	cin >> N;
	cin >> max;
	while (N != 1)
	{
		cin >> a;
		if (a > max)
		{
			max = a;
		}
	}
	cout << max << endl;
}