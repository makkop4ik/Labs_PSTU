#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Worker {
	string name = "Без имени";
	string post = "Неизвестно";
	string yearOfBirth;
	string salary;

	void print() {
		cout << "     Имя:    \t" << name << endl;
		cout << "    Должность:   \t" << post << endl;
		cout << "Год рождения: \t" << yearOfBirth << endl;
		cout << "Зарплата: \t" << salary << endl;
	}
};


Worker* deleteElements(Worker* worker, int& size, string name) {

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (worker[i].name == name) {
			count++;
		}
	}

	Worker* s = new Worker[size - count];

	for (int i = 0, j = 0; i < size; i++) {
		if (worker[i].name != name) {
			s[j] = worker[i];
			j++;
		}
	}

	delete[] worker;
	size -= count;

	return s;
}


Worker* addElement(Worker* worker, int& size, int index) {
	string name, post, yearOfBirth, salary;

	cout << "введите имя: "; getline(cin, name);
	cout << "введите должность: "; getline(cin, post);
	cout << "введите год рождения: "; getline(cin, yearOfBirth);
	cout << "введите заработную плату: "; getline(cin, salary);

	Worker stad = { name, post, yearOfBirth, salary };
	cout << endl << "создан новый стадион" << endl;
	stad.print();
	cout << endl;

	Worker* s = new Worker[size + 1];

	for (int i = 0; i < size; i++) {
		if (i < index) s[i] = worker[i];
		else if (i > index) s[i + 1] = worker[i];
		else s[i] = stad;
	}

	size += 1;
	delete[] worker;

	return s;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream file("workers.txt");
	string abs;

	int workerCount = 10;
	Worker* worker = new Worker[workerCount];


	string name, post, yearOfBirth, salary;

	for (int i = 0; i < workerCount; i++) {
		getline(file, name);
		getline(file, post);
		getline(file, yearOfBirth);
		getline(file, salary);

		worker[i] = { name, post, yearOfBirth, salary };

		getline(file, abs);
	}








}