#include <stdio.h>
#include "TreeNode.c"


int main() {
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