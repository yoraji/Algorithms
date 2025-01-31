#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int key){
    struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    head->val = key;
    head->left = NULL;
    head->right = NULL;
}

void inorderHelp(struct TreeNode* root,int *result,int* returnSize){
    if(root == NULL) return ;
    inorderHelp(root->left,result,returnSize);
    result[(*returnSize)++]= root->val;
    inorderHelp(root->right,result,returnSize);
}

int* inorderTraversal(struct TreeNode* root,int* returnSize){
    *returnSize = 0;
    int* result = (int *)malloc(1000*sizeof(int));
    inorderHelp(root,result,returnSize);
    return result;
}

int main(){
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);
    int *num;
    int* result = inorderTraversal(root,num);
    int i=0;
    while(i<100){
        printf("%d ,",result[i]);
        i++;
    }
    return 0;
}
