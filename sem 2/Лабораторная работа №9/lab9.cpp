#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

bool isA(string str)
{

	if ((str[0] == 'А') || (str[0] == 'À') || (str[0] == 'а') || (str[0] == 'à'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");


	fstream file("F1.txt");
	string str, text = "";

	while (getline(F1, str))
	{
		if (isA(str) == 1)
		{
			text += str + "\n";
		}
	}
	file.close();

	file.open("F2.txt");
	file << text;
	return 0;
}






