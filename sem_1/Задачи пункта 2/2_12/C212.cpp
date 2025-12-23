#include <iostream>

using namespace std;

int main()
{
	int N, a, min, max;
	cin >> N;
	cin >> a;
	min, max = a;
	while (N != 1) //Так как мы до цикла взяли уже одно число a
	{
		N--;
		cin >> a;
		if (a < 0)
		{
			cout << "убери отрицательное число" << endl;
			break;
		}
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	cout << min + max << endl;
}
