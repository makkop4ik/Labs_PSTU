#include <iostream>
using namespace std;

int main()
{
	int N, S;
	S = 0;
	cin >> N;
	while (N != 0)
	{
		if (N % 3 == 0)
		{
			S = S - N;
		}
		else
		{
			S = S + N;
		}
		N--;
	}
	cout << S << endl;
}