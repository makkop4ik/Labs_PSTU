#include "Vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "=== Вектор int ===" << endl;
    Vector<int> vi(3);
    cin >> vi;
    cout << "vi = " << vi << ", размер = " << (int)vi << endl;

    Vector<int> vi2(3);
    cin >> vi2;
    cout << "vi2 = " << vi2 << endl;

    Vector<int> vi3 = vi + vi2;
    cout << "vi + vi2 = " << vi3 << endl;


    cout << "\n=== Вектор float ===" << endl;
    Vector<float> vf(3);
    cin >> vf;
    cout << "vf = " << vf << endl;

    Vector<float> vf2(3);
    cin >> vf2;
    Vector<float> vf3 = vf + vf2;
    cout << "vf + vf2 = " << vf3 << endl;

 
    cout << "\n=== Вектор double ===" << endl;
    Vector<double> vd(4);
    cin >> vd;
    Vector<double> vd2(4);
    cin >> vd2;
    cout << "vd + vd2 = " << (vd + vd2) << endl;


    cout << "\n=== Вектор Time ===" << endl;
    Vector<Time> vt(2);
    cin >> vt;   
    cout << "vt = " << vt << endl;

    Vector<Time> vt2(2);
    cin >> vt2;
    Vector<Time> vt3 = vt + vt2;
    cout << "vt + vt2 = " << vt3 << endl;


    cout << "\nПервый элемент vt: " << vt[0] << endl;

    return 0;
}