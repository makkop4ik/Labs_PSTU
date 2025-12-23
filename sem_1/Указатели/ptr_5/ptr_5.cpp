#include <iostream>

using namespace std;

int main() {
	int n, ftl = 1;
	int* ptr_n = &n;
	int* ptr_ftl = &ftl;

	cin >> *ptr_n;

	for (size_t i = 1; i <= *ptr_n; i++) {
		*ptr_ftl *= i;
	}
	cout << ftl;
}