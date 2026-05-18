#pragma once
#include <iostream>
using namespace std;

class Set {
private:
    int* data;      
    int size;       
    int capacity;   

    void resize();          
    int find(int val) const; 

public:
    
    Set();                          
    Set(const Set& other);         
    ~Set();


    bool insert(int val);           
    bool remove(int val);          
    bool contains(int val) const;   

  
    Set& operator=(const Set& other);
    int operator[](int index) const;     
    operator int() const;                 
    Set operator+(const Set& other) const; 


    friend istream& operator>>(istream& in, Set& s);
    friend ostream& operator<<(ostream& out, const Set& s);


    class Iterator {
        friend class Set;
    private:
        int* ptr;    
        Iterator(int* p);
    public:
        Iterator();
        Iterator& operator++();
        Iterator operator++(int);   
        int operator*() const;
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;
};