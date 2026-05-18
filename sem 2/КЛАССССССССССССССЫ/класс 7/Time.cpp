#include "Time.h"

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
    if (minutes < 0) minutes = 0;
}

Time::Time() : minutes(0), seconds(0) {}
Time::Time(int m, int s) : minutes(m), seconds(s) { normalize(); }
Time::Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}
Time::~Time() {}

Time Time::operator+(const Time& t) const {
    int total_sec = (minutes + t.minutes) * 60 + (seconds + t.seconds);
    return Time(total_sec / 60, total_sec % 60);
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