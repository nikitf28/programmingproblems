#include <iostream>
#include <cmath>

using namespace std;

int numSum(int num){
    if (num < 10){
        return num;
    }
    else{
        return numSum(num / 10) + num % 10;
    }
}

int main(){
    int n;
    cin >>n;
    cout << numSum(abs(n));
}
