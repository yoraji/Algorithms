#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int data;
    ListNode *next;
}ListNode;
 /**
  * the problme how to merge between to sorted linkedlist 
  * the output should be one linkedlist that have the element of the two 
  * linkedlist but sorted.
  * 
**/
ListNode* mergeTwoList(ListNode* list1, ListNode*list2) {
    if(list1 == NULL)
        return list2;
    if(list == NULL)
        return list1;
    ListNode* ptr = list1;
    //point to the first element smallest element 
    if(list1->data >list2->data){
        ptr = list2;
        list2 = list2->next;
    }else{
        list1 = list1->next;
    }
    ListtNode *curr = ptr;
    while(list1 && list2){
        if(list1->data < list2->data){
            curr = list1->data;
            list1 = list1->next;
        }else{
            curr = list2->data;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    //you have to include the last element important
    if(!list1){
        curr->next = list2;
    }else
        curr->next = list1;
    return ptr;
}
