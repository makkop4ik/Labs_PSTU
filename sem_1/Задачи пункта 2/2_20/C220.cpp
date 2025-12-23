#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float n, S, a;
	cin >> n >> S;
	a = n;
	while (n != 0)
	{
		if (S == sin((n + (a / n))))
		{
			cout << "В последовательности n есть число S"<< endl;
			return 0;
		}
		n--;
	}
	cout << "В последовательности n нету числа S" << endl;
}