#include <iostream>
#include "matrix.h"

int main() {
    const int x = 3, y=3;
    double matrix_texplate[y][x] = {{1, 2, 3}, {6, 5, 6}, {8, 8, 9}};
    Matrix m1(y, x);
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            m1.set(i, j, matrix_texplate[i][j]);
        }
    }
    const int x2 = 3, y2=3;
    double matrix_texplate2[y2][x2] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix ed(y2, x2);
    for (int i = 0; i < y2; i++){
        for (int j = 0; j < x2; j++){
            ed.set(i, j, matrix_texplate2[i][j]);
        }
    }

    Matrix m1_reversed = m1.rev();
    cout <<m1_reversed;
    cout <<endl;
    cout <<m1_reversed*m1;
}
