/**
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。
 */
#include <stdio.h>
#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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

int main() {
    int arr[] = {1, 1, 2};
    struct ListNode *test = generate(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\n", printNode(NULL));
    printf("%s", printNode(deleteDuplicates(test)));
    return 0;
}