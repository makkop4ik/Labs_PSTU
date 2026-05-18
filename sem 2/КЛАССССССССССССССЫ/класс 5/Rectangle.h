#pragma once
#include "Pair.h"

class Rectangle : public Pair {
public:

    Rectangle();
    Rectangle(int w, int h);
    Rectangle(const Rectangle& r);


    virtual ~Rectangle();


    int area() const;
    int perimeter() const;


    Rectangle& operator=(const Rectangle& r);
    friend istream& operator>>(istream& in, Rectangle& r);
    friend ostream& operator<<(ostream& out, const Rectangle& r);


    virtual void Show() const override;
    virtual void Input() override;
};