#include "Time.h"
#include <iostream>
using namespace std;

void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    else if (seconds < 0) {
        int borrow = (-seconds + 59) / 60;
        minutes -= borrow;
        seconds += borrow * 60;
    }
    if (minutes < 0) {
        minutes = 0;
        seconds = 0;
    }
}

Time::Time() : minutes(0), seconds(0) {}

Time::Time(int m, int s) : minutes(m), seconds(s) {
    normalize();
}

Time::Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}

Time::~Time() {}

void Time::setMinutes(int m) {
    minutes = m;
    normalize();
}

void Time::setSeconds(int s) {
    seconds = s;
    normalize();
}

Time Time::operator-(const Time& t) const {
    int totalSec1 = minutes * 60 + seconds;
    int totalSec2 = t.minutes * 60 + t.seconds;
    int diff = totalSec1 - totalSec2;
    if (diff < 0) diff = 0;
    return Time(diff / 60, diff % 60);
}

bool Time::operator!=(const Time& t) const {
    return (minutes != t.minutes) || (seconds != t.seconds);
}

Time& Time::operator=(const Time& t) {
    if (this != &t) {
        minutes = t.minutes;
        seconds = t.seconds;
    }
    return *this;
}


istream& operator>>(istream& in, Time& t) {
    cout << "Минуты: "; in >> t.minutes;
    cout << "Секунды: "; in >> t.seconds;
    t.normalize();
    return in;
}


ostream& operator<<(ostream& out, const Time& t) {
    out << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds;
    return out;
}


fstream& operator>>(fstream& fin, Time& t) {
    fin >> t.minutes >> t.seconds;
    t.normalize();
    return fin;
}


fstream& operator<<(fstream& fout, const Time& t) {
    fout << t.minutes << " " << t.seconds << "\n";
    return fout;
}