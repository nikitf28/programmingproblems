#include <iostream>

using namespace std;

long long countNum(long long num){
    long long i = 0;
    while (num > 0){
        num/=10;
        i++;
    }
    return i;
}

long long getNthNum(long long num, long long nth){
    //int length = countNum(num);
    for (long long i = 0; i < nth; i++){
        num /= 10;
    }
    return num % 10;
}

int main(){
    long long k;
    cin >>k;
    long long sum = 0;
    long long i = 0;
    long long prev = 0;


    while (sum < k){
        i++;
        if (i > 44721){
            cout<<"TOO BIG!";
            return 0;
        }
        prev = sum;
        sum += countNum(i*i);
    }

    //cout <<i*i <<" " <<sum <<endl;

    cout <<getNthNum(i*i, sum - k);
}
