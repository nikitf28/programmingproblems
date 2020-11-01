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

    TryAgain:
        n = -1;
        cout <<"Choose function (1 - 3):\n1. y = x^4\n2. y = tg(x)\n3. y = e^x\n";
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


    cout <<"Insert range to check\n";
    long double a = -1;
    while (!(cin >> a)){
        cout << "error\n";
        cin.clear();
        fflush(stdin);
        a = -1;
        if (a <= 0){
            cout <<"Insert range to check\n";
        }
    }

    for (double x = -a; x < 0; x+=0.1){
        long double y = func(x, n);
        long double my = func(-x, n);
        cout <<my <<" " <<y <<endl;
        if (y >= 0 && my >= 0 || y <= 0 && my <= 0){
            if (abs(y-my) < E){
                if (type == -1 && y != 0){
                    cout <<"Not any type";
                    return 0;
                }
                else  if (y != 0){
                    type = 1;
                }
            }
            else {
                cout <<"Not any type";
                return 0;
            }
        }
        else {
            if (abs(y) - abs (my) < E){
                if (type == 1 && y != 0){
                    cout <<"Not any type";
                    return 0;
                }
                else if (y != 0){
                    type = -1;
                }
            }
            else {
                cout <<"Not any type";
                return 0;
            }
        }
    }
    if (type == 1){
        cout <<"Chetnaya";
        }
    else{
        cout <<"Nechetnaya";
    }
}
