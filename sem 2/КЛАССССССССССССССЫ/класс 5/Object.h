#pragma once
#include <iostream>
using namespace std;

class Object {
public:
    virtual ~Object() {}


    virtual void Show() const = 0;
    virtual void Input() = 0;
};