#include <stdio.h>
#include "sortintarray.c"

int main() {
    int data[10] = {3, 1, 2, 6, 8, 9, 0, 4, 5, 7};
//    bubbleSort(data, 10);
//    quickSort(data, 0, 9);
//    insertSort(data, 10);
    selectSort(data, 10);
    printArray(data, 10);
    return 0;
}