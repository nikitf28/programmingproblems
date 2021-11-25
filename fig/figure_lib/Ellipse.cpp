//
// Created by nikita on 25.11.2021.
//

#include "Ellipse.h"


Ellipse::Ellipse(double r1, double r2) {
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse() {
    this->r1 = 0;
    this->r2 = 0;
}
double Ellipse::calc_area() {
    return Pi * r1 * r2;
}

double Ellipse::calc_perimetr() {
    return 2 * Pi * sqrt((r1*r1 + r2*r2)/2);
}

string Ellipse::get_name() {
    return name;
}
