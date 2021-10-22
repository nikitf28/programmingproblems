#include <cmath>
#include "rational.h"
#include <iostream>
#include <iomanip>

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
    //std::cout<<"RATIONAL";
    this -> numer = n;
    this -> denom = d;
    simplify();
}

Rational Rational::operator =(const Rational& r){
    if (this == &r) {
        return *this;
    }
    numer = r.numer;
    denom = r.denom;
    return *this;
}

Rational Rational::operator +=(const Rational& r){
    //std::cout <<"numer " <<numer <<" denom" <<denom <<std::endl;
    numer = (numer*r.denom+denom*r.numer);
    denom *= r.denom;
    //std::cout <<"numer " <<numer <<" denom" <<denom <<std::endl;
    simplify();
    return *this;
}

Rational Rational::operator +(const Rational& r) const{
    Rational res(*this);
    return res += r;
}

Rational Rational::operator -() const{
    Rational r(-numer, denom);
    return r;
}

Rational Rational::operator -=(const Rational& r){
    return (*this += (-r));
}


Rational Rational::operator -(const Rational& r) const{
    Rational res(*this);
    return res -= r;
}

Rational Rational::operator *=(const Rational& r){
    numer = numer * r.numer;
    denom = denom * r.denom;
    simplify();
    return *this;
}

Rational Rational::operator *(const Rational& r) const{
    Rational res(*this);
    return res *= r;
}

Rational Rational::operator /=(const Rational& r){
    numer = numer * r.denom;
    denom = denom * r.numer;
    simplify();
    return *this;
}

Rational Rational::operator /(const Rational& r) const{
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


double Rational::toDouble(){
    return numer*1.0/denom;
}

int Rational::NOD(int a, int b){
    //std::cout <<a <<" " <<b <<std::endl;
    if (a < 0 || b < 0){
        return 1;
    }
    if (a == 0 || b == 0){
        return a+b;
    }
    if (a > b){
        return NOD(a % b, b);
    }
    else{
        return NOD(a, b % a);
    }
}

void Rational::simplify(){
    //std::cout <<"SIMPLY________-";
    if (denom < 0){
        numer = -numer;
        denom = -denom;
    }
    if (numer == 0){
        return;
    }

    int nod = NOD(numer, denom);
    numer /= nod;
    denom /= nod;
    //std::cout <<"SIMPLIFIER NUMER " <<numer <<" DENOM " <<denom <<std::endl;
}

Rational Rational::sqrtR(){
    //std::cout <<"STARTING SQRT " <<numer <<" " <<denom <<std::endl;
    Rational xn(numer, denom);
    Rational a(numer, denom);
    //Rational diff, prevdiff = xn;
    for (int i = 0; i < 20; i++){
        //std::cout <<Rational(INT32_MAX) <<std::endl;
        if (INT32_MAX/Rational(a/xn).numer < xn.denom){
            //std::cout <<INT32_MAX/Rational(a/xn).numer <<" " <<xn.denom <<std::endl;
            break;
        }
        //std::cout <<xn <<" _____________________" <<xn.toDouble() <<std::endl;
        xn = Rational(1, 2) * (xn + a / xn);
    }
    return xn;
}