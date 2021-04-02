/**
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。
 */
#include <stdio.h>
#include <malloc.h>
#include "../support/ListNode.c"

struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    struct ListNode *ret = NULL;
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    struct ListNode *realHead = NULL;
    while (cur) {
        printf("cur %p == ", cur);
        printf("cur %d\n", cur->val);
        if (ret != NULL) {
            printf("ret %p == ", ret);
            printf("ret %d\n", ret->val);
        }
        if (cur->next) {
            if (cur->val != cur->next->val) {
                if (pre == NULL) {
                    if (ret == NULL) {
                        ret = cur;
                    } else {
                        ret->next = cur;
                        ret = ret->next;
                    }
                    if (realHead == NULL) {
                        realHead = cur;
                    }
                } else {
                    if (pre->val != cur->val) {
                        if (ret == NULL) {
                            ret = cur;
                        } else {
                            ret->next = cur;
                            ret = ret->next;
                        }
                        if (realHead == NULL) {
                            realHead = cur;
                        }
                    }
                }
            } else {
                if (ret && ret->next)
                    ret->next = NULL;
            }
        } else {
            if (pre != NULL) {
                if (pre->val != cur->val) {
                    if (ret == NULL) {
                        ret = cur;
                    } else {
                        ret->next = cur;
                        ret = ret->next;
                    }
                    if (realHead == NULL) {
                        realHead = cur;
                    }
                }
            }
        }
        pre = cur;
        cur = cur->next;
    }
    return realHead;
}

int main() {
    int arr[] = {1, 1, 2};
    struct ListNode *test = generate(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\n", printNode(NULL));
    printf("%s", printNode(deleteDuplicates(test)));
    return 0;
}