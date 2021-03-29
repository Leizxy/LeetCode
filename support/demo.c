#include <stdio.h>
#include "TreeNode.c"
#include "sortintarray.c"


int main() {
    int data1[10] = {3, 1, 2, 6, 8, 9, 0, 4, 5, 7};
//    bubbleSort(data, 10);
//    quickSort(data, 0, 9);
//    insertSort(data, 10);
    selectSort(data1, 10);
    printArray(data1, 10);
    struct TreeNode *root;
    int data[16] = {-1, 1, 2, 5, 3, 4, 6, 7, -1, -1, 8, -1, -1, 9, -1, 10};
    root = createTree(data, 1, 15);
    for (int i = 1; i < 16; i++) {
        if (data[i] == -1) {
            printf("^ ");
        } else {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
    midOrder(root);
    return 0;
}