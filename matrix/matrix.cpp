//
// Created by nikita on 24.10.2021.
//

#include "matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int y, int x) {
    if (x < 0 || y < 0){
        throw MatrixException();
    }
    sizeX = x;
    sizeY = y;
    ptr = new double * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new double [sizeX];
    }
}

Matrix::Matrix(int y, int x, double **arr) {
    if (x <= 0 || y <= 0){
        throw MatrixException();
    }
    sizeX = x;
    sizeY = y;
    ptr = new double * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new double [sizeX];
    }

    for (int i = 0; i < sizeY; i++){
        for (int j = 0; j < sizeX; j++){
            ptr[i][j] = arr[i][j];
        }
    }
}

Matrix::~Matrix() = default;

void Matrix::setSize(int y, int x) {
    this -> ~Matrix();
    sizeX = x;
    sizeY = y;
    ptr = new double * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new double [sizeX];
    }
}

double Matrix::get(int y, int x) {
    if (x >= sizeX || x < 0 || y >= sizeY || y < 0){
        throw MatrixException();
    }
    else{
        return ptr[y][x];
    }
}

void Matrix::set(int y, int x, double val) {
    if (x >= sizeX || x < 0 || y >= sizeY || y < 0){
        throw MatrixException();
    }
    else{
        //cout <<"seted " <<val <<" to " << y <<" " <<x <<endl;
        ptr[y][x] = val;
    }
}

ostream &operator<<(ostream &out, Matrix v) {
    for (int j = 0; j < v.getSizeY(); j++){
        for (int i = 0; i < v.getSizeX(); i++){
            out << v.get(j, i) <<" ";
        }
        out <<endl;
    }
}

Matrix Matrix::operator=(Matrix m) {
    if (this == &m){
        return *this;
    }
    sizeX = m.getSizeX();
    sizeY = m.getSizeY();
    delete[] ptr;
    ptr = new double * [sizeY];
    for (int i = 0; i < sizeY; i++){
        ptr[i] = new double [sizeX];
    }
    for (int i = 0; i < sizeY; i++){
        for (int j = 0; j < sizeX; j++){
            ptr[i][j] = m.get(i, j);
        }
    }

    return *this;
}

Matrix operator+(Matrix m1, Matrix m2) {
    if (m1.getSizeY() != m2.getSizeY() || m1.getSizeX() != m2.getSizeX()){
        throw MatrixException();
    }
    else{
        Matrix newM(m1.getSizeY(), m1.getSizeX());
        for (int i = 0; i < m1.getSizeX(); i++){
            for (int j = 0; j < m1.getSizeY(); j++){
                newM.set(j, i, m1.get(j, i) + m2.get(j, i));
                //cout <<newM.ptr[i][j] <<" " <<endl;
            }
        }
        return newM;
    };
}

Matrix operator-(Matrix m1, Matrix m2) {
    if (m1.getSizeY() != m2.getSizeY() || m1.getSizeX() != m2.getSizeX()){
        throw MatrixException();
    }
    else{
        Matrix newM(m1.getSizeY(), m1.getSizeX());
        for (int i = 0; i < m1.getSizeX(); i++){
            for (int j = 0; j < m1.getSizeY(); j++){
                newM.set(j, i, m1.get(j, i) - m2.get(j, i));
                //cout <<newM.ptr[i][j] <<" " <<endl;
            }
        }
        return newM;
    }
}

Matrix operator*(double num, Matrix m1) {
    Matrix newM(m1.getSizeY(), m1.getSizeX());
    for (int i = 0; i < m1.getSizeX(); i++){
        for (int j = 0; j < m1.getSizeY(); j++){
            newM.set(j, i, num*m1.get(j, i));
            //cout <<newM.ptr[i][j] <<" " <<endl;
        }
    }
    return newM;
}

Matrix operator*(Matrix m1, double num) {
    return num * m1;
}

Matrix operator*(Matrix m1, Matrix m2) {
    if (m1.getSizeX() != m2.getSizeY()){
        throw MatrixException();
    }
    Matrix m3(m1.getSizeY(), m2.getSizeX());
    for (int i = 0; i < m2.getSizeX(); i++){
        for (int j = 0; j < m1.getSizeY(); j++){
            m3.set(j, i, Matrix::multyply_cell(j, i, m1, m2));
        }
    }
    return m3;
}

int Matrix::multyply_cell(int y, int x, Matrix m1, Matrix m2) {
    int sum = 0;
    for (int i = 0; i < m1.getSizeX(); i++){
        sum += m1.get(y, i) * m2.get(i, x);
    }
    return sum;
}

int Matrix::getSizeX() {
    return sizeX;
}

int Matrix::getSizeY() {
    return sizeY;
}

double Matrix::det() {
    if (getSizeX() != getSizeY()){
        throw MatrixException();
    }
    if (getSizeX() == 2){
        return get(0, 0) * get(1, 1) - get(0, 1) * get(1, 0);
    }
    double sum = 0;
    for (int k = 0; k < getSizeX(); k++){
        Matrix m_temp = minor(0, k, getSizeX());

        int d = 1;
        if (k % 2 == 1){
            d = -1;
        }
        sum += d * get(0, k) * m_temp.det();
    }
    return sum;
}

Matrix Matrix::minor(int y, int x, int size) {
    Matrix m_temp(size - 1, size - 1);
    int addY = 0;
    for (int i = 0; i < size - 1; i++){
        if (i == y){
            addY++;
        }
        int addX = 0;
        for (int j = 0; j < size - 1; j++){
            if (j == x){
                addX++;
            }
            m_temp.set(i, j, get(i + addY, j + addX));
        }
    }
    return m_temp;
}

Matrix Matrix::rev() {
    if (getSizeX() != getSizeY()){
        throw MatrixException();
    }
    double determinate = det();
    if (determinate == 0){
        throw MatrixException();
    }
    Matrix un(getSizeY(), getSizeX());
    for (int i = 0; i < un.getSizeY(); i++){
        for (int j = 0; j < un.getSizeX(); j++){
            int mn = 1;
            if ((i + j)%2 != 0){mn = -1;

            }
            un.set(i, j, mn * minor(i, j, getSizeY()).det());
        }
    }
    un = un.transpanent();
    double mul = 1 / determinate;
    un = un * mul;
    return un;
}

Matrix Matrix::transpanent() {
    Matrix m(getSizeY(), getSizeX());
    for (int i = 0; i < getSizeY(); i++){
        for (int j = 0; j < getSizeX(); j++){
            m.set(j, i, get(i, j));
        }
    }
    return m;
}

