#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book make_book() {
    string name, author;
    int year;
    cout << "Введите название книги: ";
    cin >> name;
    cout << "Введите автора: ";
    cin >> author;
    cout << "Введите год издания: ";
    cin >> year;
    Book b(name, author, year); 
    return b;                    
}


void print_book(Book b) {
    b.show();
}

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "Создание объекта без параметров" << endl;
    Book book1;
    book1.show();


    cout << "\nСоздание объекта с параметрами" << endl;
    Book book2("Война и Мир", "Толстой", 1869);
    book2.show();


    cout << "\nСоздание объекта с помощью копирования" << endl;
    Book book3 = book2;
    book3.show();


    book3.set_name("Анна Каренина");
    cout << "После изменения book3:" << endl;
    book3.show();
    cout << "book2 не изменился:" << endl;
    book2.show();


    cout << "\nпередача объекта в функцию" << endl;
    print_book(book2);


    cout << "\nВозврат объекта из функции" << endl;
    Book book4 = make_book();   
    cout << "Полученная книга:" << endl;
    book4.show();

    return 0;
}