#include "Rectangle.h"
#include <iostream>
using namespace std;


void print_pair_info(Pair& p) {
    cout << "Пара: " << p << " -> произведение = " << p.product() << endl;
}


Pair create_default_rectangle() {
    Rectangle rect(5, 10);   
    return rect;             
}

int main() {
    setlocale(LC_ALL, "Russian");

   
    Pair p1;
    cout << "p1 (по умолчанию): " << p1 << ", product = " << p1.product() << endl;

    Pair p2(3, 7);
    cout << "p2 (3,7): " << p2 << ", product = " << p2.product() << endl;


    Rectangle r1;
    cout << "\nr1 (по умолчанию): " << r1 << endl;
    cout << "Площадь = " << r1.area() << ", Периметр = " << r1.perimeter() << endl;

    Rectangle r2(4, 6);
    cout << "\nr2 (4,6): " << r2 << endl;
    cout << "Площадь = " << r2.area() << ", Периметр = " << r2.perimeter() << endl;

 
    cout << "\nПроизведение сторон: " << r2.product() << endl;

 
    cout << "\n--- Принцип подстановки ---" << endl;
    print_pair_info(r2);  


    Pair p3 = create_default_rectangle();
    cout << "Возвращённый из функции объект Pair: " << p3 << ", product = " << p3.product() << endl;


    Rectangle r3;
    cout << "\nВведите данные для прямоугольника r3:" << endl;
    cin >> r3;
    cout << "r3 = " << r3 << endl;
    cout << "Площадь r3 = " << r3.area() << endl;

    Rectangle r4;
    r4 = r3;
    cout << "r4 (копия r3): " << r4 << endl;

    return 0;
}