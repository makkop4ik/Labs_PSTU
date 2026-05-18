#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair {
protected:
    int first;
    int second;

public:

    Pair();                            
    Pair(int f, int s);                 
    Pair(const Pair& p);              

    virtual ~Pair();

    int get_first() const;
    int get_second() const;

    void set_first(int f);
    void set_second(int s);

    int product() const;

    Pair& operator=(const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};