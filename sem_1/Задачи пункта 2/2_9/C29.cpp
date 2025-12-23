#include <iostream>
using namespace std;

int main()
{
	int N, a, b, c, d, e, f;
	cin >> N;
	a = N / 2;
	b = N;
	c = N - 2;
	e = 0;

	cout << " ";
	while (a != 0)
	{
		cout << " ";
		a--;
	}
	a = N / 2;

	while (b != -1)
	{
		cout << "*";
		b--;
	}
	cout << "\n";

	while (a != 1)
	{
		b = N;
		d = a;

		while (d != 0)
		{
			cout << " ";
			d--;
		}
		cout << "*";

		while (b != 0)
		{
			cout << " ";
			b--;
		}
		cout << "*";

		f = e;
		while (f != 0)
		{
			cout << " ";
			f--;
		}

		e++;
		a--;
		cout << "*" << endl;

	}

	b = N;
	cout << " ";
	while (b != -1)
	{
		cout << "*";
		b--;
	}

	a = N / 2;
	while (a != 0)
	{
		cout << " ";
		a--;
	}
	cout << "*" << endl;

	f = N - a;
	while (f != 0)
	{
		cout << "*";
		b = N;
		while (b != 0)
		{
			cout << " ";
			b--;
		}
		cout << "*";
		a = N / 2;
		while (a != 0)
		{
			cout << " ";
			a--;
		}
		cout << "*" << endl;
		f--;
	}
	a = N / 2;
	c = a;

	while (a != 0)
	{
		cout << "*";
		b = N;
		while (b != 0)
		{
			cout << " ";
			b--;
		}
		cout << "*";

		c = a;
		while (c != 0)
		{
			cout << " ";
			c--;
		}
		cout << "*" << endl;
		a--;
	}
	b = N;
	cout << " ";
	while (b != -1)
	{
		cout << "*";
		b--;
	}
}