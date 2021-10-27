//
// Created by nikita on 24.10.2021.
//

#include "matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int x, int y) {
    if (x < 0 || y < 0){
        throw MatrixException();
    }
    sizeX = x;
    sizeY = y;
    ptr = new int * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new int [sizeX];
    }
}

Matrix::Matrix(int x, int y, int **arr) {
    if (x < 0 || y < 0){
        throw MatrixException();
    }
    sizeX = x;
    sizeY = y;
    ptr = new int * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new int [sizeX];
    }

    for (int i = 0; i < sizeY; i++){
        for (int j = 0; j < sizeX; j++){
            ptr[i][j] = arr[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < sizeY; i++){
        delete[] ptr[i];
    }
    delete[] ptr;
}

void Matrix::setSize(int x, int y) {
    this -> ~Matrix();
    sizeX = x;
    sizeY = y;
    ptr = new int * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new int [sizeX];
    }
}

int Matrix::get(int x, int y) {
    if (x >= sizeX || x < 0 || y >= sizeY || y < 0){
        throw MatrixException();
    }
    else{
        return ptr[y][x];
    }
}

void Matrix::set(int x, int y, int val) {
    if (x >= sizeX || x < 0 || y >= sizeY || y < 0){
        throw MatrixException();
    }
    else{
        ptr[y][x] = val;
    }
}

ostream &operator<<(ostream &out, const Matrix &v) {
    for (int i = 0; i < v.sizeX; i++){
        for (int j = 0; j < v.sizeY; j++){
            out << v.ptr[j][i] <<" ";
        }
        out <<endl;
    }
}

Matrix Matrix::operator=(const Matrix &m) {
    if (this == &m){
        return *this;
    }
    sizeX = m.sizeX;
    sizeY = m.sizeY;
    delete[] ptr;
    ptr = new int * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new int [sizeX];
    }
    for (int i = 0; i < sizeY; i++){
        for (int j = 0; j < sizeX; j++){
            ptr[i][i] = m.ptr[i][j];
        }
    }

    return *this;
}

Matrix operator+(const Matrix &m1, const Matrix &m2) {
    if (m1.sizeY != m2.sizeY || m1.sizeX != m2.sizeX){
        throw MatrixException();
    }
    else{
        Matrix newM(m1.sizeX, m1.sizeY);
        for (int i = 0; i < m1.sizeX; i++){
            for (int j = 0; j < m1.sizeY; j++){
                newM.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
                cout <<newM.ptr[i][j] <<" " <<endl;
            }
        }
        return newM;
    };
}



