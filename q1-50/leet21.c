/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。
 * 新链表是通过拼接给定的两个链表的所有节点组成的。
 */
#include <stdio.h>
#include "../support/ListNode.c"

//递归
struct ListNode *mergeTwoLists1(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists1(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists1(l1, l2->next);
        return l2;
    }
}


struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    } else if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    if (l1->val > l2->val) {
        void *temp = l1;
        l1 = l2;
        l2 = temp;
    }
    struct ListNode *ret = l1;
    while (l1 != NULL) {
        struct ListNode *l1next = l1->next;
        if (l1next != NULL) {
            while (l2 != NULL && l1next->val > l2->val) {
                l1->next = l2;
                l1 = l1->next;
                l2 = l2->next;
            }
            l1->next = l1next;
            l1 = l1->next;
        } else {
            l1->next = l2;
            l1 = l1->next;
            break;
        }
    }
    return ret;
}

int main() {
    int ints1[] = {1, 5, 6};
    int ints2[] = {1, 3, 4};
    struct ListNode *n1 = generate(ints1, sizeof(ints1) / sizeof(ints1[0]));
    struct ListNode *n2 = generate(ints2, sizeof(ints2) / sizeof(ints2[0]));
//    printf("%s\n", printNode(mergeTwoLists(n1, n2)));
    printf("%s\n", printNode(mergeTwoLists1(n1, n2)));
    return 0;
}