#include <iostream>
using namespace std;

int main()
{
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	cout << str << endl;

	int min = 1000, max = 0, actual = 0;
	int ind_min, ind_max;

	for (int i = 0; i < str.size(); i++)
	{
		if (i == str.size() || str[i] == ' ')
		{
			if (actual > max)
			{
				max = actual;
				ind_max = i - max;
			}
			if (actual < min)
			{
				min = actual;
				ind_min = i - min;
			}
			actual = 0;
		}
		else
		{
			actual++;
		}
	}

	cout << "Самое короткое слово в строке: ";
	for (int i = 0; i < min; i++)
	{
		cout << str[ind_min + i];
	}

	cout << endl << "Самое длинное слово в строке: ";
	for (int i = 0; i < max; i++)
	{
		cout << str[ind_max + i];
	}


}