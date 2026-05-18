#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Time {
private:
    int minutes;
    int seconds;

    void normalize();

public:
    Time();
    Time(int m, int s);
    Time(const Time& t);
    ~Time();


    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }


    void setMinutes(int m);
    void setSeconds(int s);


    Time operator-(const Time& t) const;    
    bool operator!=(const Time& t) const;   
    Time& operator=(const Time& t);


    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);


    friend fstream& operator>>(fstream& fin, Time& t);
    friend fstream& operator<<(fstream& fout, const Time& t);
};