#include <cmath>
#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational(){
    this -> numer = 0;
    this -> denom = 1;
    simplify();
}

Rational::Rational(int number){
    this -> numer = number;
    this -> denom = 1;
    simplify();
}

Rational::Rational(int n, int d){
    this -> numer = n;
    this -> denom = d;
    simplify();
}

Rational& Rational::operator +=(const Rational& r){
    numer = (numer*r.denom+denom*r.numer);
    denom *= r.denom;
    simplify();
    return *this;
}

Rational& Rational::operator +(const Rational& r) const{
    Rational res(*this);
    return res += r;
}

Rational Rational::operator -() const{
    Rational r(-numer, denom);
    return r;
}

Rational& Rational::operator -=(const Rational& r){
    return (*this += (-r));
}


Rational& Rational::operator -(const Rational& r) const{
    Rational res(*this);
    return res -= r;
}

Rational& Rational::operator *=(const Rational& r){
    numer = numer * r.numer;
    denom = denom * r.denom;
    simplify();
    return *this;
}

Rational& Rational::operator *(const Rational& r) const{
    Rational res(*this);
    return res *= r;
}

Rational& Rational::operator /=(const Rational& r){
    numer = numer * r.denom;
    denom = denom * r.numer;
    simplify();
    return *this;
}

Rational& Rational::operator /(const Rational& r) const{
    Rational res(*this);
    return res /= r;
}
Rational& Rational::operator ++(){
    numer += denom;
    return *this;
}

Rational Rational::operator ++(int){
    Rational r(*this);
    numer += denom;
    return r;
}

Rational& Rational::operator --(){
    numer -= denom;
    return *this;
}

Rational Rational::operator --(int){
    Rational r(*this);
    numer -= denom;
    return r;
}

bool Rational::operator ==(const Rational& r) const{
    return (numer==r.numer) && (denom==r.denom);
}

bool Rational::operator !=(const Rational& r) const{
    return !(*this==r);
}

bool Rational::operator >=(const Rational& r) const{
    return (numer*r.denom >= denom==r.numer);
}

bool Rational::operator <(const Rational& r) const{
    return !(*this>=r);
}

bool Rational::operator <=(const Rational& r) const{
    return (numer*r.denom <= denom==r.numer);
}

bool Rational::operator >(const Rational& r) const{
    return !(*this<=r);
}

Rational::operator int() const{
    return numer / denom;
}

Rational::operator double() const{
    return ((double)numer)/denom;
}

istream& operator >>(istream& in, Rational& r){
    in>>r.numer>>r.denom;
    return in;
}

ostream& operator <<(ostream& out, const Rational& r){
    out<<r.numer<<"/"<<r.denom;
    return out;
}

void Rational::simplify(){
    if (denom < 0){
        numer = -numer;
        denom = -denom;
    }
    for (int i = 2; i <= abs(denom) && i <= abs(numer); i++){
        if (numer % i == 0 && denom % i == 0){
            numer /= i;
            denom /= i;
            i--;
        }
    }
}

