#include <stdio.h>


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL||head->next==NULL||k == 0){
        return head;
    }
    int count = 1;
    struct ListNode* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        count++;
    }
    temp->next = head;
    int n = k%count;
    // printf("%d",n);
    if(n == 0){
        temp->next = NULL;
        return head;
    }
    int move = count-n;
    while(move!=0){
        head = head->next;
        temp = temp->next;
        move--;
    }
    temp->next = NULL;
    return head;
}

int main() {
    return 0;
}