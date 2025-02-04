#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->numChildren = 0;
    newNode->children = NULL;
    return newNode;
}

int maxDepth(struct Node* root) {
    if (!root) {
        return 0; 
    }

    int max = 0;

    for (int i = 0; i < root->numChildren; i++) {
        int childDepth = maxDepth(root->children[i]);
        if (childDepth > max) {
            max = childDepth;
        }
    }

    return max + 1;
}

int main() {
    struct Node* root = createNode(1);
    root->numChildren = 3;
    root->children = (struct Node**)malloc(3 * sizeof(struct Node*));
    root->children[0] = createNode(2);
    root->children[1] = createNode(3);
    root->children[2] = createNode(4);

    root->children[0]->numChildren = 2;
    root->children[0]->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    root->children[0]->children[0] = createNode(5);
    root->children[0]->children[1] = createNode(6);

    printf("Max Depth: %d\n", maxDepth(root));

    free(root->children[0]->children[0]);
    free(root->children[0]->children[1]);
    free(root->children[0]->children);
    free(root->children[0]);
    free(root->children[1]);
    free(root->children[2]);
    free(root->children);
    free(root);

    return 0;
}
