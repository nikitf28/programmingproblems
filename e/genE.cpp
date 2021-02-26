#include<iostream>
#include <iomanip>

using namespace std;

int main(){

    long double e = 10;
    int fac = 1;
    for (int i = 1; i < 100; i++){
        fac *= i;
        e += (1.0 / fac);
        cout <<i<<". " <<setprecision(20) <<e <<endl;
    }
}
