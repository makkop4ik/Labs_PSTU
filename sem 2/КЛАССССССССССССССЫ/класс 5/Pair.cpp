#include "Pair.h"
#include <iostream>
using namespace std;

Pair::Pair() : first(0), second(0) {}
Pair::Pair(int f, int s) : first(f), second(s) {}
Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}
Pair::~Pair() {}

int Pair::get_first() const { return first; }
int Pair::get_second() const { return second; }
void Pair::set_first(int f) { first = f; }
void Pair::set_second(int s) { second = s; }
int Pair::product() const { return first * second; }

Pair& Pair::operator=(const Pair& p) {
    if (this != &p) {
        first = p.first;
        second = p.second;
    }
    return *this;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "first: "; in >> p.first;
    cout << "second: "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

void Pair::Show() const {
    cout << *this << " -> произведение = " << product() << endl;
}

void Pair::Input() {
    cout << "Введите пару чисел:\n";
    cin >> *this;
}