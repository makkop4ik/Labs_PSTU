#include <iostream>
#include <string>

using namespace std;

struct Worker {
	string name = "Без имени";
	string post = "Неизвестно";
	int yearOfBirth;
	int salary;

	void print() {
		cout << "     Имя:    \t" << name << endl;
		cout << "    Должность:   \t" << post << endl;
		cout << "Год рождения: \t" << yearOfBirth << endl;
		cout << "Зарплата: \t" << salary << endl;
	}
};


Stadion* deleteElements(Worker* worker, int& size, string name) {

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