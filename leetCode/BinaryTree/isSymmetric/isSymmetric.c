#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode *create(int num)
{
	struct TreeNode *ptr = malloc(sizeof(struct TreeNode));
	ptr->val = num;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

bool mirror(struct TreeNode *r1, struct TreeNode *r2)
{
	if(!r1 && !r2)
		return true;
	if(!r1 || !r2 || r1->val != r2->val)
		return false;
	return mirror(r1->left,r2->right) && mirror(r1->right, r2->left);
}

bool isSymmetric(struct TreeNode *root)
{
	if(!root)
		return true;
	return (mirror(root->left, root->right));
}

int main()
{
	struct TreeNode *root = create(1);
	root->left = create(2);
	root->right = create(2);
	root->left->left = create(3);
	root->right->right = create(3);
	root->left->right = create(4);
	root->right->left = create(4);
	int num = isSymmetric(root);
	printf("result ---> %d\n", num);
	return 0;

}
