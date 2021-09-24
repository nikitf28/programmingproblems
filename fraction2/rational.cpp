#include <cmath>
#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational(Rational const &r) {
    this -> numer = r.numer;
    this -> denom = r.denom;
}

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
    std::cout<<"RATIONAL";
    this -> numer = n;
    this -> denom = d;
    simplify();
}

Rational& Rational::operator =(const Rational& r){
    if (this == &r) {
        return *this;
    }
    numer = r.numer;
    denom = r.denom;
    return *this;
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
    std::cout <<"SIMPLY________-";
    if (denom < 0){
        numer = -numer;
        denom = -denom;
    }
    if (numer == 0){
        return;
    }

    int n = numer, d = denom;
    std::cout <<n <<" " <<d <<std::endl;
    while (abs(abs(n) - abs(d)) > 1){
        if (abs(n) > abs(d)){
            n = abs(n) % d + d;
        }
        else{
            d = d % abs(n) + abs(n);
        }
        std::cout <<n <<" " <<d <<std::endl;
    }
    numer /= n;
    denom /= d;
}

Rational Rational::sqrtR(){
    std::cout <<"STARTING SQRT";
    Rational xn(numer, denom);
    Rational a(xn);
    std::cout <<"STARTING SQRT";
    for (int i = 0; i < 10; i++){
        std::cout <<"DELENIE";
        xn = Rational(1, 2) * (xn + a / xn);
    }
    return xn;
}