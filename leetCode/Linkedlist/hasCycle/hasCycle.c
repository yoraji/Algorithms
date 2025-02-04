#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node *next;
}   Node;

Node *createNode(int data){
    Node *head = (Node *)malloc(sizeof(Node *));
    head->next = NULL;
    head->data = data;
    return head;
}

void printList(Node *head){
    Node *curr = head;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

bool hasCycle(struct Node *head) {
    if(head == NULL || head->next ==NULL)
        return 0;
    struct Node *slow = head;
    struct Node *fast = head;
    while(fast != NULL || fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return 1;
    }
    return 0;
}

int main(){
    Node *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = head->next->next;

    int result = hasCycle(head);
    if(result ==1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
} 
