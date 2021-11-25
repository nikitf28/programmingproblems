//
// Created by nikita on 25.11.2021.
//
#include <string>
#include <cmath>
#include <vector>
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

#endif //FIG_FIGURE_H
