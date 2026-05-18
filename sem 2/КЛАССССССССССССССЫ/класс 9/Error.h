#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error {
private:
    string message;
public:
    Error(const string& msg) : message(msg) {}
    void what() const { cout << "Îøèáêà: " << message << endl; }
};