#include <iostream>

using namespace std;

int main() {
	int a = 4;
	int b = 7;

	cout << "a=" << a << " b=" << b << endl;

	int* ptr_a = &a;
	int* ptr_b = &b;

	int container = *ptr_b;

	*ptr_b = *ptr_a;
	*ptr_a = container;

	cout << "a=" << a << " b=" << b;
}