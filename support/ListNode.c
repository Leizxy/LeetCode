#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *generate(int *ints, int size) {
//    static struct ListNode head;
    static struct ListNode *ret;
    ret = (struct ListNode *) malloc(sizeof(struct ListNode));
//    head.val = ints[0];
//    ret = &head;
    struct ListNode *head = ret;
    int i = 0;
    while (i < size) {
        static struct ListNode *newNode;
        newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = ints[i];
        newNode->next = NULL;
        ret->next = newNode;
        ret = newNode;
        i++;
    }
    return head->next;
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
