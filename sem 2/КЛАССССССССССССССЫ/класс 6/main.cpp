#include "Set.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    Set s1;
    cout << "=== Ввод множества s1 ===" << endl;
    cin >> s1;
    cout << "s1 = " << s1 << endl;
    cout << "Размер s1 = " << (int)s1 << endl;


    cout << "\n=== Доступ по индексу ===" << endl;
    try {
        cout << "Элемент с индексом 0: " << s1[0] << endl;
        cout << "Элемент с индексом 1: " << s1[1] << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    cout << "\n=== Перебор с помощью итератора ===" << endl;
    for (Set::Iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    Set s2;
    cout << "\n=== Ввод множества s2 ===" << endl;
    cin >> s2;
    cout << "s2 = " << s2 << endl;

 
    Set s3 = s1 + s2;
    cout << "\n=== Объединение s1 + s2 ===" << endl;
    cout << "s3 = " << s3 << endl;
    cout << "Размер s3 = " << (int)s3 << endl;


    cout << "\n=== Вставка 99 в s3 ===" << endl;
    s3.insert(99);
    cout << "s3 = " << s3 << endl;

    cout << "Удаление 99 из s3" << endl;
    s3.remove(99);
    cout << "s3 = " << s3 << endl;


    Set s4 = s1;
    cout << "\n=== Копия s1 (s4) ===" << endl;
    cout << "s4 = " << s4 << endl;

    Set s5;
    s5 = s2;
    cout << "Присваивание s5 = s2: " << s5 << endl;

    return 0;
}