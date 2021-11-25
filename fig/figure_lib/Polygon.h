//
// Created by nikita on 25.11.2021.
//

#ifndef FIG_POLYGON_H
#define FIG_POLYGON_H


#include "Figure.h"

class Polygon : public Figure{
    string name = "polygon";
    vector<double> x, y;
    int n = 0;
public:
    Polygon();
    Polygon(vector<double>& x, vector<double>& y);
    void addNewCoord(double xi, double yi);
    int size();
    double calc_area() override;
    double calc_perimetr() override;
    string get_name();
};


#endif //FIG_POLYGON_H
