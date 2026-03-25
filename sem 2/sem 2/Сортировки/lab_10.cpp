#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	int size = 10;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = ((float)rand() / RAND_MAX) * 10;
	}

	cout << "Исходный массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << "Введите номер элемента в массиве, который необходимо удалить" << endl;
	int num;
	cin >> num;

	for (int i = num; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;


	int* newArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;

	cout << "Массив после удаления элемента:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl << "Введите номер позиции, куда добавить новый элемент" << endl;
	int pos;
	cin >> pos;
	cout << "Введите значение нового элемента" << endl;
	int value;
	cin >> value;


	size++;
	int* tempArr = new int[size];

	for (int i = 0; i < pos; i++)
	{
		tempArr[i] = arr[i];
	}

	tempArr[pos] = value;

	for (int i = pos; i < size - 1; i++)
	{
		tempArr[i + 1] = arr[i];
	}

	delete[] arr;
	arr = tempArr;

	cout << "Итоговый массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}