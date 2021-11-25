//
// Created by nikita on 25.11.2021.
//

#ifndef FIG_TRIANGLE_H
#define FIG_TRIANGLE_H


#include "Figure.h"

class Triangle : public Figure{
    double a, b, c;
    string name = "triangle";
public:
    Triangle();
    Triangle(double a, double b, double c);
    double calc_area() override;
    double calc_perimetr() override;
    string get_name();
};


#endif //FIG_TRIANGLE_H
