#include<iostream>

using namespace std;

long long* fib(int n){
    long long *arr;
    arr = new long long[n];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++){
        if (LLONG_MAX - arr[i - 1] < arr[i - 2]){
            cout <<"Fibonachi is too big!!!" <<endl;
            arr[i] = -1;
            break;
        }
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}

int main(){
    int n;
    cout <<"Enter number of Fibonachi: ";
    cin >>n;
    if (n < 1){
        cout <<"Use number more or equal 1";
        return 0;
    }
    long long* arr = fib(n);
    for (int i = 0; i < n; i++){
        if (arr[i] == -1){
            cout <<endl <<"Number is too big! The last number is " << i << "th." <<endl;
            break;
        }
        cout <<arr[i] <<" ";
    }
}
