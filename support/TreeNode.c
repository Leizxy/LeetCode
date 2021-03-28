#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree(int *val, int pos, int max) {
    struct TreeNode *tree;
//    printf("%d", pos);
    if (pos > max || val[pos] < 0) {
        return NULL;
    } else {
        tree = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        tree->val = val[pos];
        tree->left = createTree(val, pos * 2, max);
        tree->right = createTree(val, pos * 2 + 1, max);
        return tree;
    }
}

void midOrder(struct TreeNode *treeNode) {
    if (treeNode != NULL) {
        midOrder(treeNode->left);
        printf("%d ", treeNode->val);
        midOrder(treeNode->right);
    }
}

void test() {
    printf("111");
}