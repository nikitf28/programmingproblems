#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

long double E = 0.001;

int func(double x, int n){
    if (n == 1){
        long double y = x * x * x * x;
        return y;
    }
    if (n == 2){
        long double y = tan(x);
        return y;
    }
    if (n == 3){
        long double y = pow(M_E, x);
    }

}

int main()
{
    int type = 0;
    int n = -1;
    while (n != 1 && n != 2 && n != 3){
        cout <<"Choose function (1 - 3):\n1. y = (sin(x))^2\n2. y = tg(x)\n3. y = (1/x)*sin(x)\n";
        cin >>n;
    }



}
