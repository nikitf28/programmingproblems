#include <iostream>

using namespace std;

unsigned int factorial(unsigned int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

int main(){
    int n;
    cin >>n;
    if (n < 0){
        cout <<"Wrong number!" <<endl;
        return 0;
    }
    cout <<factorial(n);
}
