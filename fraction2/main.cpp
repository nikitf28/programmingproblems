#include <iostream>
#include "rational.h"
#include <iomanip>

using namespace std;

int main()
{
    cout <<"bla1" <<endl;
    Rational a(25, 1);
    cout <<a <<endl;
    Rational b = a.sqrtR();
    cout <<b <<endl;
    cout <<setprecision(5) <<fixed <<b.toDouble() <<endl;
}
