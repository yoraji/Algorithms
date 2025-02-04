#include<stdlib.h>
#include<stdio.h>

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

Node *removeduplicates(Node *head){
    Node *curr = head;
    if(head == NULL)
        return head;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            //store the Duplicate-list
            Node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }else
            curr = curr->next;
    }
}
void printList(Node *head){
    Node *curr = head;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    Node *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);
    printList(head);
    removeduplicates(head);
    printList(head);
    return 0;
}
