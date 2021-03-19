#include<iostream>

using namespace std;

void insertionSort(int *arr, int size){
    int buf;
    int i, j;
    for (i = 1; i < size; i++){
        buf=arr[i];
        for (j = i - 1; j >= 0 && buf < arr[j]; j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=buf;
    }
}

void heapSort(int *arr, int size){
    int buf;
    for (int i = size; i > 1; i--){
        bool flag = false;
        int sh = 0;
        for(int j = 0; j < i / 2; ){
            int largest = j, left = 2*j + 1, right = 2*j + 2;
            if (arr[left] > arr[largest]){
                buf = arr[left];
                arr[left] = arr[largest];
                arr[largest]=buf;
                flag = true;
            }
            if (right < i){
                if (arr[right] > arr[largest]){
                    buf = arr[right];
                    arr[right] = arr[largest];
                    arr[largest] = buf;
                    flag = true;
                }
            }
            if (flag && j > 0){
                j = (j - 1)/2;
                sh++;
                flag = false;
            }
            else{
                j = j + 1 + sh;
                sh = 0;
            }
        }
        buf = arr[i-1];
        arr[i-1] = arr[0];

        int largest, left, right;
        for (int j = 0; j < i /2;){

        }
    }
}

void quickSort(int *arr, int first, int last){
    int i = first, j = last;
    int buf, comp;
    comp = arr[(first+last) / 2];
    do{
        while (arr[i] < comp && i < last)
            i++;
        while (arr[j] > comp && j > first)
            j--;
        if (i <= j){
            if (arr[i] > arr[j]){
                buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
            i++;
            j--;
        }
    }while(i <= j);
    if (first < j)
        quickSort(arr, first, j);
    if (i < last)
        quickSort(arr, i, last);
}

void bucketSort(int *arr, int n){
    int **b = new int*[n];
    int *k = new int[n];
    for (int i = 0; i < n; i++){
        b[i] = new int[n];
        k[i] = 0;
    }

    for (int i = 0; i < n; i++){
        int x = arr[i] / 10;
        b[x][k[x]++] = arr[i];
    }

    for (int i = 0; i < n; i++){
        insertionSort(arr, k[i]-1);
        //quickSort(b[i], 0, k[i] - 1);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k[i]; j++)
            arr[index++] = b[i][j];
}

void mergeSort(int arr[], int size){
    int i, j, lbi, rbi, mi, lb, mb, rb;

    for (i = 1; i < size; i*=2){
        for (j = 0; j < size - 1; j+=2*i){
            lbi = 0;
            rbi = 0;
            lb = j;
            mb = j + i;
            rb = j + 2 * i;
            rb = (rb < size) ? rb : size;
            int* sortedBlock = new int[rb - lb];
            while (lb + lbi < mb && mb + rbi < rb){
                if (arr[lb + lbi] < arr[mb + rbi]){
                    sortedBlock[lbi+rbi] = arr[lb+lbi];
                    lbi++;
                }
                else{
                    sortedBlock[lbi+rbi] = arr[mb + rbi];
                    rbi++;
                }
            }

            while (lb + lbi < mb){
                sortedBlock[lbi+rbi] = arr[lb+lbi];
                lbi++;
            }
            while (mb + rbi < rb){
                sortedBlock[lbi+rbi] = arr[mb + rbi];
                rbi++;
            }
            for (mi = 0; mi < lbi+rbi; mi++){
                arr[lb+mi] = sortedBlock[mi];
            }
            delete sortedBlock;
        }
    }
}
