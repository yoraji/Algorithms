#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data) {
    struct Node* head = malloc(sizeof(struct Node));
    if (head == NULL)    
        return NULL;
    head->val = data;
    head->left = NULL;
    head->right = NULL;
    return head;
}

void binaryTree(struct Node* root, char* path, int index, int* returnSize, char*** paths) {
    if (root == NULL)
        return;
    int addlen = snprintf(path + index, 1000 - index, "%d", root->val);
    index += addlen;

    if (root->left == NULL && root->right == NULL) {
        path[index] = '\0';
        (*paths)[(*returnSize)++] = strdup(path);
    } else {
        path[index++] = '-';
        path[index++] = '>';
        binaryTree(root->left, path, index, returnSize, paths);
        binaryTree(root->right, path, index, returnSize, paths);
    }
}

char** binaryTreePaths(struct Node* root, int* returnSize) {
    char** paths = malloc(sizeof(char*) * 1000);
    char path[1000];
    *returnSize = 0; 

    binaryTree(root, path, 0, returnSize, &paths);
    return paths;
}

int main() {
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->right = create(5);
    
    int returnSize;
    char** paths = binaryTreePaths(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", paths[i]);
        free(paths[i]);
    }
    free(paths);

    return 0;
}

