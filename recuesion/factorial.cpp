#include <iostream>

using namespace std;

unsigned int factorial(unsigned int n){
    if (n == 0){
        return 1;
    }
    else{
        unsigned int num = factorial(n - 1);
        if (UINT_MAX / num < n){
            //cout <<"bla" <<endl;
            return 0;
        }
        return n * num;
    }
}

int main(){
    int n;
    cin >>n;
    if (n < 0){
        cout <<"Wrong number!" <<endl;
        return 0;
    }
    int ans = factorial(n);
    if (ans == 0){
        cout <<"Too big!" <<endl;
        return 0;
    }
    cout <<factorial(n);
}
