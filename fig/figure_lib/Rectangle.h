//
// Created by nikita on 25.11.2021.
//

#ifndef FIG_RECTANGLE_H
#define FIG_RECTANGLE_H


#include "Figure.h"

class Rectangle : public Figure{
    double a, b;
    string name = "rectangle";
public:
    Rectangle();
    Rectangle(double a, double b);
    double calc_area() override;
    double calc_perimetr() override;
    string get_name();
};


#endif //FIG_RECTANGLE_H
