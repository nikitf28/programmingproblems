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

NewVector::NewVector(const NewVector &newVector) {
    ptr = new int[newVector.capacity];
    size = newVector.size;
    capacity = newVector.capacity;
    for (int i = 0; i < size; i++){
        ptr[i] = newVector.ptr[i];
    }
}

NewVector::~NewVector() {
    delete[] ptr;
}

ostream& operator <<(ostream& out, const NewVector& v){
    out <<"[";
    for (int i = 0; i < v.size; i++){
        out <<v.ptr[i];
        if (i < v.size - 1){
            out <<", ";
        }
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



int NewVector::expland() {
    capacity *= 2;
    int* newPtr = new int[capacity];
    for (int i = 0; i < size; i++){
        newPtr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = newPtr;
}

NewVector& NewVector::operator=(const NewVector& newVector) {
    if (this == &newVector){
        return *this;
    }
    if (capacity != newVector.capacity){
        delete[] ptr;
        ptr = new int[newVector.capacity];
        capacity = newVector.capacity;
    }
    size = newVector.size;
    for (int i = 0; i < size; i++){
        ptr[i] = newVector.ptr[i];
    }
    return *this;
}

int NewVector::insert(int index, int elem) {
    if (index < 0 || index > size){
        throw NewVectorException();
    }
    if (size == capacity){
        expland();
    }
    for (int j = size - 1; j >= index; j--){
        ptr[j+1] = ptr[j];
    }
    size++;
    ptr[index] = elem;
}

int NewVector::insert(int elem) {
    insert(size, elem);
}

void NewVector::remove(int index) {
    if (index < 0 || index > size) {
        throw NewVectorException();
    }
    for (int j = index + 1; j < size; j++){
        ptr[j - 1] = ptr[j];
    }
    size--;
}

int NewVector::getSize() {
    return size;
}
