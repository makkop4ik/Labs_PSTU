#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    try {
       
        cout << "=== Создание вектора размером 12 (должно вызвать исключение) ===" << endl;
        Vector v_big(12);
    }
    catch (const Error& e) {
        e.what();
    }

    try {
       
        cout << "\n=== Создание вектора на 3 элемента ===" << endl;
        Vector v(3);
        cin >> v;
        cout << "v = " << v << endl;

        
        cout << "\n=== v + 2 (добавление 2 элементов) ===" << endl;
        Vector v2 = v + 2;
        cout << "v2 = " << v2 << endl;

       
        cout << "\n=== v2 - 1 (удаление 1 элемента с конца) ===" << endl;
        Vector v3 = v2 - 1;
        cout << "v3 = " << v3 << endl;

        
        cout << "\n=== Попытка доступа к индексу 5 (v2 размер=5) ===" << endl;
        cout << v2[5] << endl;  
    }
    catch (const Error& e) {
        e.what();
    }

    try {
        Vector v4(8);
        cout << "\n=== Вектор v4 размером 8 ===" << endl;
        cout << "v4 = " << v4 << endl;

        
        cout << "\n=== v4 + 3 (превышение MAX_SIZE) ===" << endl;
        Vector v5 = v4 + 3;
    }
    catch (const Error& e) {
        e.what();
    }

    try {
        Vector v6(5);
        cout << "\n=== Вектор v6 размером 5 ===" << endl;
        cout << "v6 = " << v6 << endl;

        
        cout << "\n=== v6 - 7 (удаление больше, чем есть) ===" << endl;
        Vector v7 = v6 - 7;
    }
    catch (const Error& e) {
        e.what();
    }

   
    try {
        Vector v8(4);
        int sz = (int)v8;  
        cout << "\nРазмер v8 = " << sz << endl;
        cout << "v8 = " << v8 << endl;
    }
    catch (const Error& e) {
        e.what();
    }

    return 0;
}