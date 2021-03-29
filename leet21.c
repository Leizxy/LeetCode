/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。
 */
#include <stdio.h>
#include "support/ListNode.c"

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *ret = l1;
    while (l1 != NULL) {
        struct ListNode *temp = l1;
        l1 = l1->next;
        while (l2 != NULL && l2->val < l1->val) {
            temp->next = l2;
            l2 = l2->next;
        }
    }
    return ret;
}

int main() {
    int ints1[] = {1, 3, 4};
    int ints2[] = {2, 5, 7};
    struct ListNode *n1 = generate(ints1, sizeof(ints1) / sizeof(ints1[0]));
    struct ListNode *n2 = generate(ints2, sizeof(ints2) / sizeof(ints2[0]));
    printf("%s\n", printNode(mergeTwoLists(n1, n2)));
    return 0;
}