#include <iostream>
using namespace std;
main()
{
	float a, b, c;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "Делить на 0 нельзя" << endl;
		return 0;
	}
		c = a / b;
		cout << c << endl;
}