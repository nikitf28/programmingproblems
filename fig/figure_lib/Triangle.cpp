//
// Created by nikita on 25.11.2021.
//

#include "Triangle.h"


Triangle::Triangle() {
    a = 0;
    b = 0;
    c = 0;
}

Triangle::Triangle(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::calc_area() {
    double p = (a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double Triangle::calc_perimetr() {
    return a + b + c;
}

string Triangle::get_name() {
    return name;
}
