//
// Created by nikita on 14.10.2021.
//
#include <iostream>
#ifndef MYVECTOR_NEWVECTOR_H
#define MYVECTOR_NEWVECTOR_H

using namespace std;

const int DEFAULT_CAPACITY = 10;

class NewVectorException {};

class NewVector{
public:
    int* ptr;
    int size;
    int capacity;

    NewVector(const NewVector& newVector);
    explicit NewVector(int startCapacity = DEFAULT_CAPACITY);
    ~NewVector();

    int insert(int elem);

    int insert(int index, int elem);

    void remove(int index);

    int getSize();

    int& operator[] (int index);

    int expland();

    friend ostream& operator << (ostream& out, const NewVector& v);
    NewVector& operator = (const NewVector& newVector);

};

#endif //MYVECTOR_NEWVECTOR_H
