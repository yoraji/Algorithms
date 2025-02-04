#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPair(struct ListNode *head){
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    while(head !=NULL && head->next != NULL){
        struct ListNode* first = head;
        struct ListNode*second = head->next;
            // swaping things 
        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
        head = first->next;
    }
    return dummy.next;
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create a linked list 1 -> 2 -> 3 -> 4
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original list:\n");
    printList(head);

    // Swap pairs
    head = swapPair(head);

    printf("List after swapping pairs:\n");
    printList(head);

    // Free the list
    freeList(head);

    return 0;
}
