#include <iostream>
#include "Figure.h"
#include <vector>

int main() {
    vector<double> polygon_x = {1, 2, 3, 4, 5, 6, 7};
    vector<double> polygon_y = {1, 2, 3, 4, 5, 6, 7};
    Polygon polygon(polygon_x, polygon_y);
    Triangle triangle(3, 4, 5);
    Ellipse ellipse(2, 4);
    Rectangle rectangle(2, 8);

    vector<Figure*> figures;
    figures.push_back(&polygon);
    figures.push_back(&triangle);
    figures.push_back(&ellipse);
    figures.push_back(&rectangle);

    double s = 0, p = 0;

    for (int i  = 0; i < figures.size(); i++){
        cout <<"This is " <<figures[i]->get_name() <<endl;
        s += figures[i]->calc_area();
        p += figures[i]->calc_perimetr();
    }
    cout <<"Sum of area: " <<s<<endl;
    cout <<"Sum of periment: " <<p <<endl;
}
