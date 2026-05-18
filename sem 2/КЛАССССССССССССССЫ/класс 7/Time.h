#pragma once
#include <iostream>
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

    int get_minutes() const { return minutes; }
    int get_seconds() const { return seconds; }
    void set_minutes(int m) { minutes = m; normalize(); }
    void set_seconds(int s) { seconds = s; normalize(); }

    Time operator+(const Time& t) const;
    Time& operator=(const Time& t);

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};