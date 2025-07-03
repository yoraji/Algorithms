#include <stdio.h>
#include <stdlib.h>


int hight(struct ListNode *root)
{
	if(!root) return 0;
	int left = hight(root-> left);
	int right = hight(root->right);
	if(right == -1 || left == -1 || abs(left - right) > 1)
		return -1;
	return (left > right ? left : right) + 1;
}
