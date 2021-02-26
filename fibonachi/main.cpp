#include<iostream>

using namespace std;

int fib(int n, long long* arr){
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int main(){
    int n;
    cout <<"Enter number of Fibonachi: ";
    cin >>n;
    long long *arr;
    arr = new long long[n];
    fib(n, arr);
    for (int i = 0; i < n; i++){
        cout <<arr[i] <<" ";
    }
}
