#pragma once
#include <iostream>
using namespace std;

class Time {
private:
    int min;  
    int sec;   

public:
 
    Time();                           
    Time(int m, int s);              
    Time(const Time& t);            


    ~Time();


    int get_min() const;
    int get_sec() const;


    void set_min(int m);
    void set_sec(int s);


    Time& operator=(const Time& t);   
    Time operator-(const Time& t) const; 
    bool operator!=(const Time& t) const;


    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);

private:
    
    void normalize();
};