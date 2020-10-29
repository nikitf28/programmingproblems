#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

long double func(int n){
    long double ans = 1;
    long double body = 1 + 1.0/n;
    for (int i = 0; i < n; i++){
        ans *= body;
    }
    return ans;
}

int main()
{
    long double e, oldSin;
    int x = 1;
    cout << "Insert ebselent: " <<endl;
    while (!(cin >> e)){
            cout << "error\n";
            cin.clear();
            fflush(stdin);
    }

    cout <<x <<" " <<func(x)/x <<endl;
    oldSin = func(x);
    x+=1;
    cout <<x <<" " <<func(x) <<endl;
    while (abs(oldSin - func(x)) > e){
        oldSin = func(x);
        x+=1;
        cout <<x <<" " <<func(x) <<endl;
    }
}
