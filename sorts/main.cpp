#include <iostream>
#include <cstdlib>
#include "sortings.h"
#include <ctime>
#include <iomanip>

using namespace std;

int* copyArray(int *arr, int n){
    int *newArr = new int[n];
    for (int i = 0; i < n; i++){
        newArr[i] = arr[i];
    }
    return newArr;
}

void printArr(int *arr, int size){
    for (int i = 0; i < size; i++){
        cout <<arr[i] <<" ";
    }
    cout <<endl <<endl;
}

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

    int n = 30, b = 10, e = 50;
    int* arr2 = genUnicPosled(n, b, e);
    //int* arr2[] = {7, 6, 5, 4, 1, 3, 4};
    heapSort(arr2, n);
    printArr(arr2, n);
/*
    double times[24];
    int n = 1000, b = -100000, e = 100000;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 10; j++){
            cout <<i <<" " <<j <<endl;
            int start, end;

            int* arr1 = genPosled(n, b, e);
            int* arr2 = genUnicPosled(n, b, e);
            int* arr11 = copyArray(arr1, n);
            int* arr21 = copyArray(arr2, n);
            int* arr12 = copyArray(arr1, n);
            int* arr22 = copyArray(arr2, n);
            int* arr13 = copyArray(arr1, n);
            int* arr23 = copyArray(arr2, n);

            start = clock();
            insertionSort(arr11, n);
            end = clock();
            times[i*6 + 0] -= (start - end) * 1.0 / CLOCKS_PER_SEC;

            start = clock();
            insertionSort(arr21, n);
            end = clock();
            times[i*6 + 1] -= (start - end) * 1.0 / CLOCKS_PER_SEC;

            //cout <<"insert" <<endl;

            start = clock();
            heapSort(arr12, n);
            end = clock();
            times[i*6 + 2] -= (start - end) * 1.0 / CLOCKS_PER_SEC;

            //cout <<seconds <<endl;

            start = clock();
            heapSort(arr22, n);
            end = clock();
            times[i*6 + 3] -= (start - end) * 1.0 / CLOCKS_PER_SEC;

            start = clock();
            quickSort(arr13, 0, n-1);
            end = clock();
            times[i*6 + 4] -= (start - end) * 1.0 / CLOCKS_PER_SEC;

            //cout <<seconds <<endl;

            start = clock();
            quickSort(arr23, 0, n-1);
            end = clock();
            times[i*6 + 5] -= (start - end) * 1.0 / CLOCKS_PER_SEC;

            //cout <<"heap" <<endl;
        }
        n*=10;
    }

    for (int i = 0; i < 24; i++){
        times[i] *= 100;
    }

    cout <<"NotUnic,    Unic\n" <<"Insertation\n" <<"10^3: "
    <<times[0] <<" " <<times[1] <<endl <<"10^4: " <<times[6] <<" " <<times[7] <<endl
     <<"10^5: " <<times[12] <<" " <<times[13] <<endl <<"10^6: " <<times[18] <<" " <<times[19] <<endl;

    cout <<"Heap\n" <<"10^3: "
    <<times[2] <<" " <<times[3] <<endl <<"10^4: " <<times[8] <<" " <<times[9] <<endl
     <<"10^5: " <<times[14] <<" " <<times[15] <<endl <<"10^6: " <<times[20] <<" " <<times[21] <<endl;

    cout <<"Quick\n" <<"10^3: "
    <<times[4] <<" " <<times[5] <<endl <<"10^4: " <<times[10] <<" " <<times[11] <<endl
     <<"10^5: " <<times[16] <<" " <<times[17] <<endl <<"10^6: " <<times[22] <<" " <<times[23];
*/
}
