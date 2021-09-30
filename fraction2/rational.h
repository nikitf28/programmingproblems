#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED
#include <iostream>
using namespace std;
class Rational{

public:

    Rational& operator =(const Rational& r);
    Rational& operator +=(const Rational& r);
    Rational& operator +(const Rational& r) const;
    Rational& operator -(const Rational& r) const;
    Rational operator -() const;
    Rational& operator -=(const Rational& r);
    Rational& operator *=(const Rational& r);
    Rational& operator *(const Rational& r) const;
    Rational& operator /=(const Rational& r);
    Rational& operator /(const Rational& r) const;

    Rational& operator ++();
    Rational operator ++(int);
    Rational& operator --();
    Rational operator --(int);

    bool operator ==(const Rational& r) const;
    bool operator !=(const Rational& r) const;
    bool operator >=(const Rational& r) const;
    bool operator <=(const Rational& r) const;
    bool operator >(const Rational& r) const;
    bool operator <(const Rational& r) const;

    operator int() const;
    operator double() const;

    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator << (ostream& out, const Rational& r);
    int numer, denom;

    void simplify();

    Rational(Rational const &r);
    Rational();
    Rational(int number);
    Rational(int n, int d);
    Rational sqrtR();
};
#endif // RATIONAL_H_INCLUDED
