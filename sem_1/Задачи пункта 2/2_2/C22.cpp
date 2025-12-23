#include <iostream>
using namespace std;

int main()
{
	int N, S, i;
	cin >> N;
	S = 1;
	i = 0;
	if (N > 0)
	{
		while (i < N)
		{
			i++;
			S = S * i;
		}
		cout << S << endl;
	}
	else
	{
		cout << "ВВОД неккоректен" << endl;
		return 0;
	}
}