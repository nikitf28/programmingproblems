#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    vector<int> x, y;
    while (!(cin >> n)){
            cout << "error\n";
            cin.clear();
            fflush(stdin);
    }

    for (int i = 0; i < n; i++){
        //cout <<"CYC " <<i <<endl;
        int Xi, Yi;
        while (!(cin >> Xi)){
            cout << "error\n";
            cin.clear();
            fflush(stdin);
        }
        while (!(cin >> Yi)){
                cout << "error\n";
                cin.clear();
                fflush(stdin);
        }
        x.push_back(Xi);
        y.push_back(Yi);
    }
    int minX = 99999999, minY = 99999999, pos = 0;
    int prevX, prevY, nextX, nextY;

    for (int i = 0; i < n; i++){
        if (minX > x[i]){
            minX = x[i];
            minY = y[i];
            pos = i;
        }
        if (minX == x[i]){
            if (minY > y[i]){
                minX = x[i];
                minY = y[i];
                pos = i;
            }
        }
    }

    if (pos == 0){
        prevX = x[n-1];
        prevY = y[n-1];
    }
    else{
        prevX = x[pos-1];
        prevY = y[pos-1];
    }

    if (pos == n-1){
        nextX = x[0];
        nextY = y[0];
    }
    else{
        nextX = x[pos+1];
        nextY = y[pos+1];
    }

    if (prevY < nextY){
        cout <<"clockwise";
    }
    else{
        cout <<"counter-clockwise";
    }

}
