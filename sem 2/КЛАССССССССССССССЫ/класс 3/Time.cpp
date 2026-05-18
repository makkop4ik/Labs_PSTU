#include "Time.h"


void Time::normalize() {
    if (sec >= 60) {
        min += sec / 60;
        sec %= 60;
    }
    else if (sec < 0) {

        int borrow = (-sec + 59) / 60; 
        min -= borrow;
        sec += borrow * 60;
    }

    if (min < 0) {
        min = 0;
        sec = 0;
    }
}


Time::Time() : min(0), sec(0) {}


Time::Time(int m, int s) : min(m), sec(s) {
    normalize(); 
}


Time::Time(const Time& t) : min(t.min), sec(t.sec) {}


Time::~Time() {}


int Time::get_min() const { return min; }
int Time::get_sec() const { return sec; }


void Time::set_min(int m) { min = m; }
void Time::set_sec(int s) {
    sec = s;
    normalize();
}


Time& Time::operator=(const Time& t) {
    if (this != &t) {
        min = t.min;
        sec = t.sec;
    }
    return *this;
}


Time Time::operator-(const Time& t) const {
    int total_sec1 = min * 60 + sec;
    int total_sec2 = t.min * 60 + t.sec;
    int diff = total_sec1 - total_sec2;
    if (diff < 0) diff = 0;   
    return Time(diff / 60, diff % 60);
}


bool Time::operator!=(const Time& t) const {
    return (min != t.min) || (sec != t.sec);
}


istream& operator>>(istream& in, Time& t) {
    cout << "¬ведите минуты: ";
    in >> t.min;
    cout << "¬ведите секунды: ";
    in >> t.sec;
    t.normalize();
    return in;
}


ostream& operator<<(ostream& out, const Time& t) {
    out << t.min << ":" << (t.sec < 10 ? "0" : "") << t.sec;
    return out;
}