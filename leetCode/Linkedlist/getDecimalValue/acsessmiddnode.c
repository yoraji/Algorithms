#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
// accessing the midel node :

struct ListNode* MiddleOfLinkedList(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL || fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
