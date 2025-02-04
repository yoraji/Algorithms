#include<stdlib.h>
#include<stdio.h>

struct ListNode{
    int data;
    struct ListNode *next;
};
// create node function 
// and the main function also 

struct ListNode*reverseList(struct ListNode* head){
    struct ListNode *curr = head;
    struct ListNode *prev=NULL;
    struct ListNode *store;
    while(curr != NULL){
        store = curr->next;
        curr->next = prev->next;
        prev = curr;
        curr = store;
    }
    return prev;
}
