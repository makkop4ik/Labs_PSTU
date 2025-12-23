#include <iostream>
using namespace std;

int main()
{
	int N, s;
	cin >> N;
	cin >> s;
	while (N >= 10)
	{
		if (s == (N % 10))
		{
			cout << "Цифра S есть в записи числа N" << endl;
			break;
		}
		N = N / 10;
	}
	if (N < 10)
	{
		cout << "Цифры S нету в записи числа N" << endl;
	}
}