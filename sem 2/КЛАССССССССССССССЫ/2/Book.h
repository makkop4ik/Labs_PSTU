#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string name;  
    string author; 
    int year;      

public:
    
    Book();                         
    Book(string n, string a, int y); 
    Book(const Book& other);        

    
    ~Book();

    
    string get_name() const;
    string get_author() const;
    int get_year() const;

    
    void set_name(string n);
    void set_author(string a);
    void set_year(int y);

    
    void show() const;
};

#endif