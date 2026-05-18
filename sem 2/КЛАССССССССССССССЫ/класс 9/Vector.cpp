#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;

Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector(int s) : size(s) {
    if (s > MAX_SIZE)
        throw Error("размер превышает MAX_SIZE");
    if (s < 0)
        throw Error("размер не может быть отрицательным");
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = 0;
}

Vector::Vector(const Vector& v) : size(v.size) {
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
}

Vector::~Vector() {
    delete[] data;
}

int& Vector::operator[](int index) {
    if (index < 0 || index >= size)
        throw Error("индекс вне диапазона");
    return data[index];
}

const int& Vector::operator[](int index) const {
    if (index < 0 || index >= size)
        throw Error("индекс вне диапазона");
    return data[index];
}

Vector Vector::operator+(int n) const {
    if (n < 0)
        throw Error("количество добавляемых элементов не может быть отрицательным");
    if (size + n > MAX_SIZE)
        throw Error("добавление приведёт к превышению MAX_SIZE");
    Vector result(size + n);
    for (int i = 0; i < size; i++)
        result.data[i] = data[i];
   
    return result;
}

Vector& Vector::operator+=(int n) {
    if (n < 0)
        throw Error("количество добавляемых элементов не может быть отрицательным");
    if (size + n > MAX_SIZE)
        throw Error("добавление приведёт к превышению MAX_SIZE");
    int* newData = new int[size + n];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    for (int i = size; i < size + n; i++)
        newData[i] = 0;
    delete[] data;
    data = newData;
    size += n;
    return *this;
}

Vector Vector::operator-(int n) const {
    if (n < 0)
        throw Error("количество удаляемых элементов не может быть отрицательным");
    if (n > size)
        throw Error("попытка удалить больше элементов, чем есть в векторе");
    if (size - n == 0) {
        return Vector(); 
    }
    Vector result(size - n);
    for (int i = 0; i < size - n; i++)
        result.data[i] = data[i];
    return result;
}

Vector& Vector::operator-=(int n) {
    if (n < 0)
        throw Error("количество удаляемых элементов не может быть отрицательным");
    if (n > size)
        throw Error("попытка удалить больше элементов, чем есть в векторе");
    if (size - n == 0) {
        delete[] data;
        data = nullptr;
        size = 0;
        return *this;
    }
    int* newData = new int[size - n];
    for (int i = 0; i < size - n; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    size -= n;
    return *this;
}

Vector& Vector::operator=(const Vector& v) {
    if (this == &v) return *this;
    delete[] data;
    size = v.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
    return *this;
}

ostream& operator<<(ostream& out, const Vector& v) {
    out << "[ ";
    for (int i = 0; i < v.size; i++) {
        out << v.data[i];
        if (i != v.size - 1) out << ", ";
    }
    out << " ]  размер=" << v.size;
    return out;
}

istream& operator>>(istream& in, Vector& v) {
    for (int i = 0; i < v.size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        in >> v.data[i];
    }
    return in;
}