#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *generate(int *ints, int size) {
    static struct ListNode head;
    static struct ListNode *ret;
//    printf("generate node %d", head->val);
    head.val = ints[0];
    ret = &head;
//    printf("generate node %d\n", head.val);
    int i = 1;
    while (i < size) {
        static struct ListNode *newNode;
        newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = ints[i];
        newNode->next = NULL;
        ret->next = newNode;
        ret = newNode;
        i++;
//        printf("generate node %p\n", newNode);
//        printf("generate node %d\n", newNode->val);
    }
    return &head;
}

char *printNode(struct ListNode *pNode) {
    static char result[300];
    int i = 0;
    result[i] = '[';
    i++;
    while (pNode) {
        printf("print %p -> ", pNode);
        printf("print %d\n", pNode->val);

        result[i] = pNode->val + 48;
        i++;
        result[i] = ',';
        i++;
        pNode = pNode->next;
    }
    if (result[i - 1] == ',') {
        result[i - 1] = ']';
    } else {
        result[i] = ']';
        i++;
    }
    result[i] = '\0';
    return result;
}
