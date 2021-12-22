//
// Created by nikita on 24.10.2021.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iosfwd>

using namespace std;

class MatrixException{};

class Matrix {
private:
    int sizeX;
    int sizeY;
    double** ptr;
public:

    Matrix(int x, int y);
    Matrix(int x, int y, double **arr);
    ~Matrix();
    void setSize(int y, int x);

    double get(int y, int x);
    void set(int y, int x, double val);
    int getSizeX();
    int getSizeY();

    static int multyply_cell(int x, int y, Matrix m1, Matrix m2);

    friend ostream& operator << (ostream& out, Matrix v);

    Matrix operator =(Matrix m);

    friend Matrix operator +(Matrix m1, Matrix m2);
    friend Matrix operator -(Matrix m1, Matrix m2);
    friend Matrix operator *(double num, Matrix m1);
    friend Matrix operator *(Matrix m1, double num);
    friend Matrix operator *(Matrix m1, Matrix m2);

    double det();
    Matrix minor(int y, int x, int size);
    Matrix rev();
    Matrix transpanent();
};


#endif //MATRIX_MATRIX_H
