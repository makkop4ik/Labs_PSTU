#include <iostream>
using namespace std;

int main()
{
	int N, a, s;
	a, s = 0;
	cin >> N;
	while (N != 0)
	{
		a = N % 10;
		N = N / 10;
		s = s * 10 + a;
	}
	cout << s << endl;
}