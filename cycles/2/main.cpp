#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{

    double a, b;
    cout <<"Enter A and B for oval\n";
    while (!(cin >> a) || !(cin >>b)){
            cin.clear();
            fflush(stdin);
            a = 0;
            b = 0;
            cout <<"Enter A and B\n";
    }
    double x, y;
    cout <<"Enter X and Y\n";
    while (!(cin >> x) || !(cin >>y)){
            cin.clear();
            fflush(stdin);
            x = 0;
            y = 0;
            cout <<"Enter X and Y\n";
    }
    cout <<(x*x)/(a*a) + (y*y)/(b*b)<<endl;
    if ((x*x)/(a*a) + (y*y)/(b*b) <= 1){
        cout <<"X and Y is INSIDE oval!";
    }
    else{
        cout <<"X and Y is OUTSIDE oval!";
    }
    return 0;
}
