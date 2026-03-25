#include <iostream>
#include <complex>

using namespace std;


double add(double a, double b) {
    cout << "Вызвана функция для вещественных чисел" << endl;
    return a + b;
}


complex<double> add(complex<double> a, complex<double> b) {
    cout << "Вызвана функция для комплексных чисел" << endl;
    return a + b;
}


int main() {

    double x, y;
    cin >> x >> y;
    double result_double = add(x, y);
    cout << "Результат: " << result_double << endl;
    cout << endl;
    return 0;
}
