/**
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 */
#include <stdio.h>
#include "../support/ListNode.c"

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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }
    if (listsSize == 1) {
        return lists[0];
    }
    struct ListNode *ret = NULL;
    /*for (int i = 0; i < listsSize; ++i) {
        ret = mergeTwoLists1(ret, lists[i]);
    }*/
    int i = 0;
    while (i < listsSize) {
        if (lists[i]!=NULL){
            ret = mergeTwoLists1(ret,lists[i]);
        }
        i++;
    }
    return ret;
}

int main() {
    return 0;
}