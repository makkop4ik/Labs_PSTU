#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, s, i;
	float a, mx;
	cin >> n;

	mx = sin(n);
	cout << mx << " ";
	s = 1;
	i = 1;

	while (i != n)
	{
		a = sin(n + i / double(n));
		cout << a << " ";

		if (a > mx) {
			mx = a;
			s = 0;
		}
		if (abs(a - mx) < 0.000001) {
			s++;
		}
		i++;
	}
	cout << endl << s << " " << mx;


	return 0;
}