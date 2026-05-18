#include "Set.h"
#include <algorithm>
using namespace std;



void Set::resize() {
    capacity = (capacity == 0) ? 4 : capacity * 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

int Set::find(int val) const {

    for (int i = 0; i < size; i++)
        if (data[i] == val) return i;
    return -1;
}



Set::Set() : data(nullptr), size(0), capacity(0) {}

Set::Set(const Set& other) : data(nullptr), size(other.size), capacity(other.capacity) {
    if (capacity > 0) {
        data = new int[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
}

Set::~Set() {
    delete[] data;
}



bool Set::insert(int val) {
    if (find(val) != -1) return false; 
    if (size == capacity) resize();

    int pos = 0;
    while (pos < size && data[pos] < val) pos++;
    for (int i = size; i > pos; i--)
        data[i] = data[i - 1];
    data[pos] = val;
    size++;
    return true;
}

bool Set::remove(int val) {
    int idx = find(val);
    if (idx == -1) return false;
    for (int i = idx; i < size - 1; i++)
        data[i] = data[i + 1];
    size--;
    return true;
}

bool Set::contains(int val) const {
    return find(val) != -1;
}



Set& Set::operator=(const Set& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    if (capacity > 0) {
        data = new int[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    else {
        data = nullptr;
    }
    return *this;
}

int Set::operator[](int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("»ндекс вне границ множества");
    return data[index];
}

Set::operator int() const {
    return size;
}

Set Set::operator+(const Set& other) const {
    Set result = *this;

    for (int i = 0; i < other.size; i++)
        result.insert(other.data[i]);
    return result;
}



istream& operator>>(istream& in, Set& s) {
    int n, val;
    cout << "¬ведите количество элементов: ";
    in >> n;
    cout << "¬ведите " << n << " уникальных целых чисел:" << endl;
    for (int i = 0; i < n; i++) {
        in >> val;
        s.insert(val);
    }
    return in;
}

ostream& operator<<(ostream& out, const Set& s) {
    out << "{ ";
    for (int i = 0; i < s.size; i++) {
        out << s.data[i];
        if (i != s.size - 1) out << ", ";
    }
    out << " }";
    return out;
}



Set::Iterator::Iterator(int* p) : ptr(p) {}
Set::Iterator::Iterator() : ptr(nullptr) {}

Set::Iterator& Set::Iterator::operator++() {
    ptr++;
    return *this;
}

Set::Iterator Set::Iterator::operator++(int) {
    Iterator old = *this;
    ptr++;
    return old;
}

int Set::Iterator::operator*() const {
    return *ptr;
}

bool Set::Iterator::operator==(const Iterator& other) const {
    return ptr == other.ptr;
}

bool Set::Iterator::operator!=(const Iterator& other) const {
    return ptr != other.ptr;
}

Set::Iterator Set::begin() const {
    return Iterator(data);
}

Set::Iterator Set::end() const {
    return Iterator(data + size);
}