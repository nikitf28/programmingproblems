//
// Created by nikita on 25.11.2021.
//

#include <string>
#include <cmath>
#include <vector>

#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Polygon.h"

using namespace std;

#ifndef FIG_FIGURE_H
#define FIG_FIGURE_H



class Polygon_Exception{};

class Figure {
    string name = "abstract figure";
protected:
    double Pi = 3.141592653589793;
public:
    Figure();
    virtual double calc_area() = 0;
    virtual double calc_perimetr() = 0;
    virtual string get_name()=0;
};



#endif //FIG_FIGURE_H
