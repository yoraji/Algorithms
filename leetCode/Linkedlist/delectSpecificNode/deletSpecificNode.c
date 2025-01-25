#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* delectspecificNode(struct Node* last, int key){
    if(last == NULL)
        return NULL;
    struct Node* curr = last->next;
    struct Node* prev = last;
    // If the  node to be delected is the only node in the list
    if(curr == last && curr->data == key ){
        free(curr);
        last = NULL;
        return last;
    }
    // Traversal the list to find the node to be delected
    while(curr != last && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    // If the node to be delected is found
    if(curr->data == key){
        prev->next = curr->next;
        if(curr == last){
            last = prev;
        }
        free(curr);
    } else {
        printf("Node with data %d not found.\n", key);
    }
    return last;
}

void printList(struct Node* last){
    if(last == NULL){
        printf("List is Empty");
        return;
    }
    struct Node* head = last->next;
    // it will loop to the end
    while(1){
        printf("%d ",head->data);
        if(head == last->next) break;
    }
    printf("\n");
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create circular linked list: 2, 3, 4
    struct Node* first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node* last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    // Delete a specific node
    int key = 3;
    last = deleteispecificNode(last, key);

    printf("List after deleting node %d: ", key);
    printList(last);

    return 0;
}
