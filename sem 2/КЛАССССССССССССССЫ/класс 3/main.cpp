#include "Time.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    Time t1;
    cout << "t1 (по умолчанию): " << t1 << endl;


    Time t2(5, 120); 
    cout << "t2 (5,120): " << t2 << endl;


    Time t3(t2);
    cout << "t3 (копия t2): " << t3 << endl;


    Time a, b;
    cout << "\nВведите первый интервал:\n";
    cin >> a;
    cout << "Введите второй интервал:\n";
    cin >> b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;


    Time c = a - b;
    cout << "a - b = " << c << endl;


    if (a != b)
        cout << "a != b" << endl;
    else
        cout << "a == b" << endl;


    Time d;
    d = a;
    cout << "d = a: " << d << endl;

   
    d.set_min(10);
    d.set_sec(45);
    cout << "d после set_min(10), set_sec(45): " << d << endl;
    cout << "get_min() = " << d.get_min() << ", get_sec() = " << d.get_sec() << endl;

    return 0;
}