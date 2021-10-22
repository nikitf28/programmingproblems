#include <iostream>
#include "rational.h"
#include <iomanip>

using namespace std;

int main()
{
    Rational r;
    cin >>r;
    cout <<r.sqrtR() <<" " <<r.sqrtR().toDouble();
    /*
    Rational a(2);
    Rational b(7);
    Rational c(-4);
    Rational D = (b*b) - Rational(4)*a*c;
    cout <<D.sqrtR().toDouble() <<" DESC" <<endl;
    Rational x1 = (-b - D.sqrtR())/Rational(2);
    Rational x2 = (-b + D.sqrtR())/Rational(2);
    cout <<x1 <<" " <<x2 <<endl;
    cout <<setprecision(5) <<fixed <<x1.toDouble() <<" " <<x2.toDouble() <<endl;*/
}
