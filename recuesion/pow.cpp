#include <iostream>
#include <cmath>

using namespace std;

int fastPow(int x, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return pow(x*x, n/2);
    }
    else{
        return x * pow(x, n - 1);
    }
}

int main(){
    int x, n;
    cin >>x >>n;
    int num = fastPow(x, abs(n));
    if (n < 0){
        cout <<1.0/num;
    }
    else{
        cout <<num;
    }
}
