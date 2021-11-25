//
// Created by nikita on 25.11.2021.
//

#include "Polygon.h"

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
