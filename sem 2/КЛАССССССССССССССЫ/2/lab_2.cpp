#include "Book.h"
#include <iostream>
using namespace std;

// конструктор без параметров
Book::Book() {
    name = "";
    author = "";
    year = 0;
    cout << "Конструктор без параметров " << this << endl;
}

// конструктор с параметрами
Book::Book(string n, string a, int y) {
    name = n;
    author = a;
    year = y;
    cout << "конструктор с параметрами " << this << endl;
}

// конструктор копирования
Book::Book(const Book& other) {
    name = other.name;
    author = other.author;
    year = other.year;
    cout << "конструктор копирования " << this << endl;
}

// деструктор
Book::~Book() {
    cout << "Деструктор " << this << endl;
}

// селекторы
string Book::get_name() const {
    return name;
}

string Book::get_author() const {
    return author;
}

int Book::get_year() const {
    return year;
}

// модификаторы
void Book::set_name(string n) {
    name = n;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_year(int y) {
    year = y;
}

// вывод информации
void Book::show() const {
    cout << "Книга: " << name << ", автор: " << author << ", год: " << year << endl;
}