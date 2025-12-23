#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, x, fact = 1;
	float y = 0;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		fact = 1;
		for (int j = 1; j <= i; j++) {
			fact *= j;
		}

		y += pow(x, i) / fact;
	}

	cout << y;

	return 0;
}