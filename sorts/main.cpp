#include <iostream>
#include <cstdlib>
#include "sortings.h"

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
    int n, b, e;
    cin >>n >>b >>e;
    int* arr1 = genPosled(n, b, e);
    //printArr(arr1, n);

    int* arr2 = genUnicPosled(n, b, e);
    //printArr(arr2, n);

    int* arr11 = copyArray(arr1, n);
    insertionSort(arr11, n);
    printArr(arr11, n);

    int* arr21 = copyArray(arr2, n);
    insertionSort(arr21, n);
    printArr(arr21, n);

    int* arr12 = copyArray(arr1, n);
    heapSort(arr12, n);
    printArr(arr12, n);

    int* arr22 = copyArray(arr2, n);
    heapSort(arr22, n);
    printArr(arr22, n);

    int* arr13 = copyArray(arr1, n);
    quickSort(arr13, 0, n - 1);
    printArr(arr13, n);

    int* arr23 = copyArray(arr2, n);
    quickSort(arr23, 0, n - 1);
    printArr(arr23, n);
}
