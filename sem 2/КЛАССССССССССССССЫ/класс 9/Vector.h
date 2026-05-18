#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Vector {
private:
    int* data;  
    int size;   

public:
    
    Vector();               
    Vector(int s);          
    Vector(const Vector& v);
    ~Vector();

  
    int& operator[](int index);
    const int& operator[](int index) const;
    operator int() const { return size; }  

    Vector operator+(int n) const; 
    Vector& operator+=(int n);     

    Vector operator-(int n) const;  
    Vector& operator-=(int n);      


    Vector& operator=(const Vector& v);


    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};