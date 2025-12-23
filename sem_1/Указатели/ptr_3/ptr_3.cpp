#include <iostream>

using namespace std;

int main() {
	float a = 7.03;
	float b = 12.44;

	cout << "a=" << a << " b=" << b << endl;

	float* ptr_a = &a;
	float* ptr_b = &b;

	float sum = *ptr_a + *ptr_b;

	cout << "a + b = " << sum << endl;

	return 0;
}
