#include <iostream>
#include "newVector.h"

int main() {
    NewVector v = NewVector(10);
    for (int i = 0; i < 10; i++) {
        v.insert(i*10);
    }
    NewVector v2(v);
    NewVector v3 = v2;
    v.insert(111);
    v.insert(2, 200);
    v.remove(5);
    v.remove(5);
    v.remove(5);
    v.remove(5);
    cout <<v <<endl;
    cout <<v2 <<endl;
    v3[0] = 999999;
    cout <<v3 <<endl;
    cout <<v.getSize() <<endl;
}
