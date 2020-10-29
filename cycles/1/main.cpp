#include <iostream>

using namespace std;

int checkX4(long double a){
    long double x = -a;
    while (x <= a + 0.1){
        long double y = x * x * x * x;
        cout <<fixed <<y <<endl;
        x += 0.1;
    }
}


int main()
{
    int n = -1;
    while (n != 1 && n != 2 && n != 3){
        cout <<"Choose function (1 - 3):\n1. y = x^4\n2. y = tg(x)\n3. y = e^x\n";
        cin >>n;
    }

    long double a = -1;
    while (a < 0){
        cout <<"Insert x func(-x)...func(x)\n";
        cin >>a;
    }

    if (n == 1){
        checkX4(a);
    }
}
