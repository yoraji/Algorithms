#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct  Node{
    int val;
    struct Node* right;
    struct Node* left; 
};

bool isSameTree(struct Node* p, struct Node* q) {
    if(p == NULL && q == NULL)
        return 1;
    if(p == NULL || q == NULL)
        return 0;
    if(p->val != q->val)
        return 0;
    if(isSameTree(p->left,q->left) == 0){
        return 0;
    }
    if(isSameTree(p->right,q->right) == 0){
        return 0;
    }
    return 1;
}

struct Node* create(int val){
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->val=val;
    ptr->left=ptr->right = NULL;
    return ptr;
}

int main(){
    // The First Node
    struct Node* root1 =create(1);
    root1->left = create(2);
    root1->right = create(3);
    //The Second Node
    struct Node* root2 = create(1);
    root2->left = create(2);
    root2->right= create(3);
    if(isSameTree(root1,root2)){
        printf("True\n");
    }else{
        printf("False\n"); 
    }
}
