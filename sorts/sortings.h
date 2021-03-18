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
        buf=arr[i-1];
        arr[i-1]=arr[0];
        arr[0]=buf;
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
