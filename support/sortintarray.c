void printArray(int *data, int n) {
    for (int i = 0; i < n; ++i) {
        if (i != n - 1) {
            printf("%d -> ", *(data + i));
        } else {
            printf("%d;", *(data + i));
        }
    }
    printf("\n");
}

//冒泡
void bubbleSort(int *data, int n);

//快速排序
void quickSort(int data[], int low, int high);

//插入排序
void insertSort(int *data, int n);

//选择排序
void selectSort(int *data, int n);
//shell排序
//堆排序
//归并排序
//基数排序

void bubbleSort(int *data, int n) {
    int temp;
    for (int j = 0; j < n - 1; ++j) {
        for (int i = 0; i < n - j - 1; ++i) {
            if (*(data + i) > *(data + i + 1)) {
                temp = *(data + i);
                *(data + i) = *(data + i + 1);
                *(data + i + 1) = temp;
                printf("j is %d : ", j);
                printArray(data, n);
            }
        }
    }
}

int findPos(int data[], int low, int high) {
    int t = data[low];
    while (low < high) {
        while (low < high && data[high] >= t) {
            high--;
        }
        data[low] = data[high];
        printArray(data, 10);
        while (low < high && data[low] <= t) {
            low++;
        }
        data[high] = data[low];
        printArray(data, 10);
    }
    data[low] = t;
    printArray(data, 10);
    return low;
}

void quickSort(int data[], int low, int high) {
    if (low > high) return;
    int pos = findPos(data, low, high);
//    printf("pos %d : \n", pos);
    quickSort(data, low, pos - 1);
    quickSort(data, pos + 1, high);
}

void insertSort(int *data, int n) {
    for (int i = 1; i < n; ++i) {
        int j;
        if (*(data + i) < *(data + i - 1)) {
            int temp = *(data + i);
            for (j = i - 1; j >= 0 && temp < *(data + j); j--) {
                *(data + j + 1) = *(data + j);
            }
            *(data + j + 1) = temp;
        }
    }
}

void selectSort(int data[], int n) {
    int min;
    for (int i = 0; i < n - 1; ++i) {
        min = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        if (i != min) {
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
}