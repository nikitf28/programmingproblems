#include <iostream>
#include "newVector.h"

int main() {
    NewVector v = NewVector(10);
    for (int i = 0; i < 130; i++) {
        v.insert(i);
    }

    cout <<v <<" " << v.size <<endl;
    v[10] = 9999999;
    cout <<v[10] <<" " <<v[11] <<endl;
}
