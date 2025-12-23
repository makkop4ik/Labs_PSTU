#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << (-b / 2 * a) + sqrt((-b / 2 * a) * (-b / 2 * a) - (c / a)) << endl;
	cout << (-b / 2 * a) - sqrt((-b / 2 * a) * (-b / 2 * a) - (c / a)) << endl;
}