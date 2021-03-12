#include <iostream>
#include <cstdlib>
//#include <ctime>

using namespace std;

int* genPosled(int n, int b, int e){
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = rand() % (e-b) + b;
    }
    return arr;
}

int* genUnicPosled(int n, int b, int e){
    int *temp, *arr;
    temp = new int[e - b + 1];
    arr = new int[n];
    for (int i = b; i <= e; i++){
        //cout <<i <<" " <<i-b <<endl;
        temp[i-b] = i;
    }
    int emax = e - b + 1;
    for (int i = 0; i < n; i++){
        int r = rand() % (emax);
        arr[i] = temp[r];
        //cout <<i <<" " <<r <<endl;
        temp[r] = temp[emax-1];
        emax--;
    }
    return arr;
}

int main(){
    int n, b, e;
    cin >>n >>b >>e;
    int* arr = genPosled(n, b, e);
    for (int i = 0; i < n; i++){
        cout <<arr[i] <<" ";
    }

    cout <<"\n\n\n";

    int* arr2 = genUnicPosled(n, b, e);
    for (int i = 0; i < n; i++){
        cout <<arr2[i] <<" ";
    }
}
