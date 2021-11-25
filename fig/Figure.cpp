//
// Created by nikita on 25.11.2021.
//

#include "Figure.h"



Figure::Figure() {

}

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

Polygon::Polygon() {

}

Polygon::Polygon(vector<double> &x, vector<double> &y) {
    if (x.size() != y.size()){
        throw Polygon_Exception();
    }
    if (x.size() < 3){
        throw Polygon_Exception();
    }
    for (int i = 0; i < x.size(); i++){
        this->x.push_back(x[i]);
    }
    for (int i = 0; i < y.size(); i++){
        this->y.push_back(y[i]);
    }
    n = x.size();
}

void Polygon::addNewCoord(double xi, double yi) {
    x.push_back(xi);
    y.push_back(yi);
    n++;
}

double Polygon::calc_area() {
    double sum = 0;

    for (int i = 0; i < n -1; i++){
        sum += x[i] * y[i+1];
    }
    sum += x[n-1] * y[0];

    for (int i = 0; i < n - 1; i++){
        sum -= x[i+1] * y[i];
    }

    sum -= x[0] * y[n-1];

    return abs(sum) / 2;

}

int Polygon::size() {
    return n;
}

double Polygon::calc_perimetr() {
    double perimetr = 0;
    for (int i = 0; i < n - 1; i++){
        perimetr += sqrt((x[i+1] - x[i])*(x[i+1] - x[i])+(y[i+1] - y[i])*(y[i+1] - y[i]));
    }
    perimetr += sqrt((x[0] - x[n-1])*(x[0] - x[n-1])+(y[0] - y[n-1])*(y[0] - y[n-1]));
    return perimetr;
}

string Polygon::get_name() {
    return to_string(n)+"-polygon";
}
