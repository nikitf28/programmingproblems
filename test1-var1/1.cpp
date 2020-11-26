#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> a;
int m, n;

int findPow(int n){
    int i = 1;
    while (n > 0){
        n /= 10;
        i++;
    }
    return i;
}

int drawLine(int k, int l, int go){
    if (k - go >= 0 && k - go < m){
        for (int i = max(l - go, 0); i <= min(l+go, n-1); i++){
            a[k-go][i] = go + 1;
        }
    }
    if (k + go < m && k + go >= 0){
        for (int i = max(l - go, 0); i <= min(l+go, n-1); i++){
            a[k+go][i] = go + 1;
        }
    }

    if (l - go >= 0 && l - go < n){
        for (int i = max(k - go, 0); i <= min(k+go, m-1); i++){
            a[i][l-go] = go + 1;
        }
    }

    if (l + go < n && l + go >= 0){
        for (int i = max(k - go, 0); i <= min(k+go, m-1); i++){
            a[i][l+go] = go + 1;
        }
    }
}

int main(){
    cin >>m >>n;
    a.resize(m);
    for (int i = 0; i < m; i++){
        a[i].resize(n);
    }

    int k, l;
    cin >>k >>l;


    for (int i = 0; i < max(abs(k) + m + 1, abs(l) + n + 1); i++){
        drawLine(k-1, l-1, i);
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout <<setw(findPow(max(abs(k) + m + 1, abs(l) + n + 1))) <<setfill(' ') <<a[i][j] ;
        }
        cout <<endl;
    }
}
