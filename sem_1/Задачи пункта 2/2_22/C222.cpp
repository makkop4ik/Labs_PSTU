#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, i;
	double a, b;
	cin >> n;

	i = 1;
	c = sin(n);

	while (i != n)
	{
		a = sin(n + i / double(n));
		if (a > b) { b = a; }
		i++;
	}

	cout << b;


	return 0;
}