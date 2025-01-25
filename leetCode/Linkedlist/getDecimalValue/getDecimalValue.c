#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
 };
/*
 * the new lesson that i get is that in the bitwise first i return an
 * integer so is all good 
 * and i store the bits in a interger 
 * two thing */


int getDecimalValue(struct ListNode* head){
    struct ListNode* curr = head;
    int result = 0;
    while(curr != NULL){
        result = (result >> 1) | curr->val;
        curr = curr->next;
    }
    return result;
}

