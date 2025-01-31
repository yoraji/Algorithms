#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create(int val) {
    struct TreeNode *ptr = malloc(sizeof(struct TreeNode));
    if (!ptr)
        return NULL;
    ptr->val = val;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (!root) return NULL;// finishing searchin on the node
    if (root->val < low) { // in the case of the content is less then (low) just return
        struct TreeNode* right = trimBST(root->right, low, high);
        free(root);
        return right;
    }
    if (root->val > high) {// the opposite
        struct TreeNode* left = trimBST(root->left, low, high);
        free(root);
        return left;
    }
    root->left = trimBST(root->left, low, high);// move to the left (recursion)
    root->right = trimBST(root->right, low, high); // move to the right (recursion)
    return root;
}

void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode *head = create(0);
    head->left = create(2);
    head->right = create(3);
    head->left->left = create(1);
    head->right->left = create(4);

    printf("Original Tree: ");
    printTree(head);
    printf("\n");

    head = trimBST(head, 0, 4);

    printf("Trimmed Tree: ");
    printTree(head);
    printf("\n");

    freeTree(head);

    return 0;
}
