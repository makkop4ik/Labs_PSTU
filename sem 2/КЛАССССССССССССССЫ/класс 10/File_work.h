#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


int make_file(const char* fname) {
    fstream stream(fname, ios::out | ios::trunc);
    if (!stream) return -1;
    int n;
    cout << "Количество записей: "; cin >> n;
    Time t;
    for (int i = 0; i < n; i++) {
        cout << "Запись " << i + 1 << ":\n";
        cin >> t;
        stream << t;
    }
    stream.close();
    return n;
}


int print_file(const char* fname) {
    fstream stream(fname, ios::in);
    if (!stream) return -1;
    Time t;
    int cnt = 0;
    while (stream >> t) {
        cout << ++cnt << ". " << t << endl;
    }
    stream.close();
    return cnt;
}


int del_unequal(const char* fname, const Time& val) {
    fstream temp("temp.txt", ios::out);
    fstream in(fname, ios::in);
    if (!in) return -1;
    Time t;
    int kept = 0, total = 0;
    while (in >> t) {
        total++;
        if (t == val) {    
            temp << t;
            kept++;
        }
    }
    in.close();
    temp.close();
    remove(fname);
    rename("temp.txt", fname);
    return kept;   
}


int decrement_equal(const char* fname, const Time& val, const Time& delta) {
    fstream temp("temp.txt", ios::out);
    fstream in(fname, ios::in);
    if (!in) return -1;
    Time t;
    int changed = 0;
    while (in >> t) {
        if (t == val) {
            t = t - delta; 
            changed++;
        }
        temp << t;
    }
    in.close();
    temp.close();
    remove(fname);
    rename("temp.txt", fname);
    return changed;
}


int add_to_begin(const char* fname, int k) {
    if (k <= 0) return 0;
    fstream temp("temp.txt", ios::out);

    cout << "Введите " << k << " новых записей (каждая в формате минуты и секунды):\n";
    Time t;
    for (int i = 0; i < k; i++) {
        cout << "Новая запись " << i + 1 << ":\n";
        cin >> t;
        temp << t;
    }

    fstream in(fname, ios::in);
    if (in) {
        while (in >> t) {
            temp << t;
        }
        in.close();
    }
    temp.close();
    remove(fname);
    rename("temp.txt", fname);
    return k;  
}