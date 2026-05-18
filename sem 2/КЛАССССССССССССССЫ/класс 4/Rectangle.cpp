#include "Rectangle.h"


Rectangle::Rectangle() : Pair() {}


Rectangle::Rectangle(int w, int h) : Pair(w, h) {}


Rectangle::Rectangle(const Rectangle& r) : Pair(r) {}


Rectangle::~Rectangle() {}


int Rectangle::area() const {
    return first * second;
}


int Rectangle::perimeter() const {
    return 2 * (first + second);
}


Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        Pair::operator=(r);  
    }
    return *this;
}


istream& operator>>(istream& in, Rectangle& r) {
    cout << "Введите ширину: ";
    in >> r.first;
    cout << "Введите высоту: ";
    in >> r.second;
    return in;
}


ostream& operator<<(ostream& out, const Rectangle& r) {
    out << "Прямоугольник: ширина=" << r.first << ", высота=" << r.second;
    return out;
}