#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}   ListNode;
//function to create a new node
ListNode *createNode(int val){
    ListNode* head = (ListNode*)malloc(sizeof(ListNode *));
    head->next = NULL;
    head->val  = val;
    return head;
}

//function to add two numbers represented by linked List
ListNode *AddTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode dummy;
    dummy.next = NULL;
    ListNode* curr = &dummy;
    int carry = 0;
    while(l1 != NULL ||l2 != NULL ||carry != 0)
    {
        //get the value from the current nodes
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 !=NULL) ? l2->val : 0;
        int sum = val1 +val2+ carry;
        carry = sum /10;
        int value = sum % 10;
        //we the change te null by the lide that we created;
        curr->next = createNode(value);
        // then we move on;
        curr = curr->next;
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }
    return dummy.next;
}

void printList(ListNode* head){
    while(head !=NULL){
        printf("%d ",head->val);
        head = head->next;
        if(head != NULL)
            printf("-> ");
    }
    printf("\n");
}

void freeList(ListNode* head){
    while(head != NULL){
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}
// Example usage
int main() {
    // Create the first linked list: 2 -> 4 -> 3 (represents number 342)
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // Create the second linked list: 5 -> 6 -> 4 (represents number 465)
    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // Add the two numbers
    ListNode* result = AddTwoNumbers(l1, l2);

    // Print the result list
    printf("Result: ");
    printList(result);

    // Free the allocated memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
