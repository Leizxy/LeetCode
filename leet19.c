/**
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */
#include <stdio.h>
#include "support/ListNode.c"

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (head->next == NULL && n == 1) {
        return NULL;
    }
    struct ListNode *fast = head;
    int diff = n;
    while (diff > 0 && fast != NULL) {
        fast = fast->next;
        diff--;
    }
    if (fast == NULL) {
        return head->next;
    }
    struct ListNode *slow = head;
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main() {
    int arr[] = {1, 2, 3};
    struct ListNode *test = generate(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\n", printNode(test));
    printf("%s", printNode(removeNthFromEnd(test, 3)));
    return 0;
}