/**
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

返回同样按升序排列的结果链表。

 */
#include <stdio.h>
#include "support/ListNode.c"

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *pre = head;
    struct ListNode *move = head;
    while (move->next != NULL) {
        if (move->val == move->next->val) {
            move = move->next;
            pre->next = NULL;
        } else {
            move = move->next;
            pre->next = move;
            pre = move;
        }
    }
    return head;
}
//简便写法

struct ListNode *deleteDuplicates2(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *p = head;
    while (p->next != NULL && p != NULL) {
        if (p->val == p->next->val) {
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    return head;
}

int main() {
    int arr[] = {1};
    struct ListNode *test = generate(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\n", printNode(deleteDuplicates2(test)));
    return 0;
}