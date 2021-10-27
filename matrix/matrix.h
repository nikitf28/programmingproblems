//
// Created by nikita on 24.10.2021.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iosfwd>

using namespace std;

class MatrixException{};

class Matrix {
public:
    int** ptr;
    int sizeX;
    int sizeY;

    Matrix(int x, int y);
    Matrix(int x, int y, int **arr);
    ~Matrix();
    void setSize(int x, int y);

    int get(int x, int y);
    void set(int x, int y, int val);


    friend ostream& operator << (ostream& out, const Matrix& v);

    Matrix operator =(const Matrix& m);

    friend Matrix operator +(const Matrix& m1, const Matrix& m2);
};


#endif //MATRIX_MATRIX_H
