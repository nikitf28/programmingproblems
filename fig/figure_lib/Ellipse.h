//
// Created by nikita on 25.11.2021.
//

#ifndef FIG_ELLIPSE_H
#define FIG_ELLIPSE_H


#include "Figure.h"

class Ellipse : public Figure{
    double r1, r2;
    string name = "ellipse";
public:
    Ellipse();
    Ellipse(double r1, double r2);
    double calc_area() override;
    double calc_perimetr() override;
    string get_name() override;
};



#endif //FIG_ELLIPSE_H
