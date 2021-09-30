#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    cout <<"bla1" <<endl;
    Rational a(25, 1);
    Rational b(25, 1);
    cout <<"SLOJENIE " << a + b <<endl;
    cout <<"WICHITANIE " <<a - b <<endl;
    cout <<"UMNOJENIE " <<a*b <<endl;
    cout <<endl <<"DELENIE" <<a/b <<endl;
    cout <<"bla2" <<endl;
    //cout <<a.sqrtR();
}
