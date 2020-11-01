#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

long double E = 0.001, T = 0;

long double func(double x, int n){
    //cout <<x <<" " <<n <<endl;
    if (n == 1){
        long double y = sin(x)*sin(x);
        return y;
    }
    if (n == 2){
        long double y = tan(x);
        return y;
    }
    if (n == 3){
        long double y = sin(x)*1.0/x;
        return y;
    }

}

int main()
{
    int type = 0;
    int n = -1;

    TryAgain:
        n = -1;
        cout <<"Choose function (1 - 3):\n1. y = sin(x)^2 (T = Pi)\n2. y = tg(x) (T = Pi)\n3. y = (1/x)*sin(x) (T = 2 * Pi)\n";
        while (true){
            if (!(cin >> n)){
                cin.clear();
                fflush(stdin);
                n = -1;
                cout <<"bla";
                goto TryAgain;
            }
            if (n != 1 && n != 2 && n != 3){
                goto TryAgain;
            }
            break;
        }

    if (n == 1 || n == 2){
        T = M_PI;
    }
    else if (n == 3){
        T = M_PI * 2;
    }

    for (double i = 0; i < T; i+=0.1){
        cout <<"X = " <<i <<" " <<2*T + i <<" " <<3*T + i <<" " <<4*T + i <<" " <<5*T + i <<endl;
        cout <<"Y = " <<func(i, n) <<" " <<func(2*T + i, n) << " " <<func(3*T + i, n) <<" " <<func(4*T + i, n) <<" " <<func(5*T + i, n) <<endl;
        if (abs(func(i, n) - func(2*T + i, n)) > E){
            cout <<"\n<----Wrong period!---->" <<endl;
            return 0;
        }
        if (abs(func(i, n) - func(3*T + i, n)) > E){
            cout <<"\n<----Wrong period!---->" <<endl;
            return 0;
        }
        if (abs(func(i, n) - func(4*T + i, n)) > E){
            cout <<"\n<----Wrong period!---->" <<endl;
            return 0;
        }
        if (abs(func(i, n) - func(5*T + i, n)) > E){
            cout <<"\n<----Wrong period!---->" <<endl;
            return 0;
        }
    }
    cout <<"\n<----Period is OK!---->" <<endl;
    return 0;
}
