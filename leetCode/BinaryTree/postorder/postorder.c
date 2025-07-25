#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children; 
};


int postcounter(struct Node* root)
{
    if(!root)
        return 0;
    int count = 1;
    for(int i = 0;i < root->numChildren; i++)
    {
        count += postcounter(root->children[i]);
    }
    return count;
}

void function(struct Node* root,int *arr,int *index)
{
    if(!root)
        return ;
    for(int i = 0;i < root->numChildren; i++)
    {
        function(root->children[i],arr,index);
    }
    arr[*index] = root->val;
    (*index)++;
}

int* postorderTraversal(struct Node* root, int* returnSize) {
    int size = postcounter(root);
    int *arr = malloc(sizeof(int) * (size));
    *returnSize = size;
    int index = 0;
    function(root, arr,&index);
    return arr;
}

// ...existing code...
struct Node* createSampleTree() {
    struct Node* root = malloc(sizeof(struct Node));
    root->val = 1;
    root->numChildren = 3;
    root->children = malloc(sizeof(struct Node*) * 3);
    
    struct Node* child1 = malloc(sizeof(struct Node));
    child1->val = 2;
    child1->numChildren = 0;
    child1->children = NULL;

    struct Node* child2 = malloc(sizeof(struct Node));
    child2->val = 3;
    child2->numChildren = 0;
    child2->children = NULL;

    struct Node* child3 = malloc(sizeof(struct Node));
    child3->val = 4;
    child3->numChildren = 0;
    child3->children = NULL;

    root->children[0] = child1;
    root->children[1] = child2;
    root->children[2] = child3;

    return root;
}

void freeTree(struct Node* root) {
    if (!root) return;
    
    for (int i = 0; i < root->numChildren; i++) {
        freeTree(root->children[i]);
    }
    
    free(root->children);
    free(root);
}

int main() {
    struct Node *root = createSampleTree();
    int returnSize;
    int *result = postorderTraversal(root, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result); 
    freeTree(root);
    return 0;
}
