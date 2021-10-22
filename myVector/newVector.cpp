//
// Created by nikita on 14.10.2021.
//

#include "newVector.h"


NewVector::NewVector(int startCapacity){
    if (startCapacity <= 0){
        capacity = DEFAULT_CAPACITY;
    }
    else{
        capacity = startCapacity;
    }
    ptr = new int[capacity];
    size = 0;
}

NewVector::~NewVector() {
    delete[] ptr;
}

ostream& operator <<(ostream& out, const NewVector& v){
    out <<"[";
    for (int i = 0; i < v.size; i++){
        out <<v.ptr[i] <<", ";
    }
    out <<"]";
    return out;
}

int& NewVector::operator[](int index) {
    if (index >= size || index < 0){
        throw NewVectorException();
    } else{
        return ptr[index];
    }
}

int NewVector::insert(int elem) {
    if (size + 1 > capacity){
        expland();
    }
    ptr[size] = elem;
    size++;
    return size - 1;
}

int NewVector::expland() {
    capacity *= 2;
    int* newPtr = new int[capacity];
    for (int i = 0; i < size; i++){
        newPtr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = newPtr;
}