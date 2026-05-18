#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* data;      
    int length;  

public:

    Vector();                    
    Vector(int n);               
    Vector(const Vector& other); 
    ~Vector();


    int size() const { return length; }
    T& operator[](int index);
    const T& operator[](int index) const;
    operator int() const { return length; }   

    
    Vector operator+(const Vector& other) const;

    
    Vector& operator=(const Vector& other);


    template <typename U>
    friend ostream& operator<<(ostream& out, const Vector<U>& v);
    template <typename U>
    friend istream& operator>>(istream& in, Vector<U>& v);
};



template <typename T>
Vector<T>::Vector() : data(nullptr), length(0) {}

template <typename T>
Vector<T>::Vector(int n) : length(n) {
    data = new T[length];
    for (int i = 0; i < length; i++)
        data[i] = T(); 
}

template <typename T>
Vector<T>::Vector(const Vector& other) : length(other.length) {
    data = new T[length];
    for (int i = 0; i < length; i++)
        data[i] = other.data[i];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= length)
        throw out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= length)
        throw out_of_range("Index out of range");
    return data[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    int new_len = (length < other.length) ? length : other.length;
    Vector<T> result(new_len);
    for (int i = 0; i < new_len; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return *this;
    delete[] data;
    length = other.length;
    data = new T[length];
    for (int i = 0; i < length; i++)
        data[i] = other.data[i];
    return *this;
}


template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& v) {
    out << "[ ";
    for (int i = 0; i < v.length; i++) {
        out << v.data[i];
        if (i != v.length - 1) out << ", ";
    }
    out << " ]";
    return out;
}

template <typename T>
istream& operator>>(istream& in, Vector<T>& v) {
    cout << "Введите " << v.length << " элементов: ";
    for (int i = 0; i < v.length; i++)
        in >> v.data[i];
    return in;
}