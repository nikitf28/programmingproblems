#include <iostream>

using namespace std;

double pow(double x, int n){
    if (n == 0){
        return 1;
    }
    if (n < 0){
        return pow(1/x, -n);
    }
    if (n % 2 == 0){
        return pow(x*x, n/2);
    }
    else{
        return x * pow(x, n - 1);
    }
}

int main(){
    double x, n;
    cin >>x >>n;
    cout <<pow(x, n);
}
