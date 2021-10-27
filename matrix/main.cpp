#include <iostream>
#include "matrix.h"

int main() {
    const int x = 3, y=3;
    int matrix_texplate[x][y] = {{2, 3, 4}, {2, 9, 8}, {1, 4, 7}};
    int** ptr = new int * [y];
    for (int i = 0; i < y; i++){
        ptr[i] = new int [x];
    }

    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            ptr[i][j] = matrix_texplate[j][i];
        }
    }
    Matrix m(x, y, ptr);
    Matrix m2(x, y, ptr);
    cout <<m + m2 <<endl << "LOOOOL";
    Matrix m3(m + m2);
    cout <<m3;
}
