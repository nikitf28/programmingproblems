#include<iostream>
#include<vector>

using namespace std;

void printNewVector(int a, int b, int ad, int bd, vector<int> coords){
    for (int i = 0; i < coords.size(); i++){
        if (i == a){
            cout <<coords[a] + ad <<" ";
        }
        else if (i == b){
            cout <<coords[b] + bd <<" ";
        }
        else{
            cout <<coords[i] <<" ";
        }
    }
    cout <<endl;
}

void goHorse(int a, int b, vector<int> coords){
    int x = coords[a], y = coords[b];
    if (x + 2 < 8 && y + 1 < 8){
        printNewVector(a, b, 2, 1, coords);
    }
    if (x + 1 < 8 && y + 2 < 8){
        printNewVector(a, b, 1, 2, coords);
    }
    if (x - 2 >= 0 && y - 1 >= 0){
        printNewVector(a, b, -2, -1, coords);
    }
    if (x - 1 >= 0 && y - 2 >= 0){
        printNewVector(a, b, -1, -2, coords);
    }


    if (x - 2 >= 0 && y + 1 < 8){
        printNewVector(a, b, -2, 1, coords);
    }
    if (x - 1 >= 0 && y + 2 < 8){
        printNewVector(a, b, -1, 2, coords);
    }
    if (x + 2 < 8 && y - 1 >= 0){
        printNewVector(a, b, 2, -1, coords);
    }
    if (x + 1 < 8 && y - 2 >= 0){
        printNewVector(a, b, 1, -2, coords);
    }

}

int main(){
    int n;
    cout <<"Enter number of coords: ";
    cin >>n;
    cout <<"Enter coords: ";
    vector<int> coords;
    for (int i = 0; i < n; i++){
        int a;
        cin >>a;
        coords.push_back(a);
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            goHorse(i, j, coords);
        }
    }
}
