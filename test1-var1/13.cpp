#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string num;
    cin >>num;
    vector<int> a;

    a.resize(num.length());
    for (int i = 0; i < num.length(); i++){
        a[i] = num[i] - '0';
    }

    for (int i = 1; i < a.size(); i++){
        for (int j = 0; j < i; j++){
            if (a[j] > a[i]){
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = a.size()-1; i >= 0; i--){
        cout <<a[i];
    }
}
