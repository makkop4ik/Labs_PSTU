#include "Pair.h"
#include "Rectangle.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    Vector v(5);


    Pair* p1 = new Pair(3, 7);
    Pair* p2 = new Pair();
    Rectangle* r1 = new Rectangle(4, 6);
    Rectangle* r2 = new Rectangle();

 
    cout << "Ввод данных для Pair:\n";
    p2->Input();
    cout << "\nВвод данных для Rectangle:\n";
    r2->Input();


    v.Add(p1);
    v.Add(p2);
    v.Add(r1);
    v.Add(r2);


    cout << "\n=== Вектор объектов ===\n";
    cout << v;


    cout << "\n=== Прямой вызов методов ===" << endl;
    cout << "p1 произведение = " << p1->product() << endl;
    cout << "r1 площадь = " << r1->area() << ", периметр = " << r1->perimeter() << endl;


    cout << "\n=== Удаляем второй элемент (индекс 1) ===\n";
    v.Del(1);
    cout << v;


    return 0;
}