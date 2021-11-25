//
// Created by nikita on 25.11.2021.
//

#include "Rectangle.h"


Rectangle::Rectangle() {
    a = 0;
    b = 0;
}

Rectangle::Rectangle(double a, double b) {
    this->a = a;
    this->b = b;
}

double Rectangle::calc_area() {
    return a * b;
}

double Rectangle::calc_perimetr() {
    return (a + b) * 2;
}

string Rectangle::get_name() {
    return name;
}
