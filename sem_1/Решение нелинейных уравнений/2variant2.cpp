//f(x) = 3*sin(sqrt(x)) + 0.35x - 3,8
// f'(x) = (3 * cos(sqrt(x))) / (2 * sqrt(x))
// f''(x) = 3 * ( -cos(sqrt(x))/(2 * sqrt(x)) - sin(sqrt(x))/2) / (2 * x)
// [2; 3]

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x, xPrev;
	//f(b) * f''(b) > 0
	double eps = 0.000001;
	x = 3; //x0 = b;
	xPrev = 0;

	while (abs(x - xPrev) > eps)
	{
		xPrev = x;
		x = xPrev - (3 * sin(sqrt(xPrev)) + 0.35 * xPrev - 3.8) / ((3 * cos(sqrt(xPrev))) / (2 * sqrt(xPrev)) + 0.35);
	}
	cout << "Корень:" << x << endl;
	return 0;
}