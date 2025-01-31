#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
                return true;
        if(root1 == NULL || root2 == NULL)
                return false;
        if(root1->val != root2->val)
                return false;
        return(flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left) ||
                        flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left));
}

int main() {
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);
    root1->right->left = createNode(6);
    root1->left->right->left = createNode(7);
    root1->left->right->right = createNode(8);

    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->left->right = createNode(6);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);
    root2->right->left->left = createNode(8);
    root2->right->left->right = createNode(7);

    bool result = flipEquiv(root1, root2);
    printf("Example 1: %s\n", result ? "true" : "false");

    struct TreeNode* root3 = createNode(1);
    root3->left = createNode(2);
    root3->right = createNode(3);

    struct TreeNode* root4 = createNode(1);
    root4->left = createNode(3);
    root4->right = createNode(2);
    root4->right->left = createNode(4);

    result = flipEquiv(root3, root4);
    printf("Example 2: %s\n", result ? "true" : "false");

    return 0;
}
