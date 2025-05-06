#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int *values = malloc(sizeof(int) * 10000);
    int *res = malloc(sizeof(int) * 10000);
    int stack[10000];
    int top = -1;
    int i = 0;

    struct ListNode* curr = head;
    while (curr) {
        values[i] = curr->val;
        res[i] = 0;
        while (top >= 0 && values[stack[top]] < curr->val) {
            res[stack[top]] = curr->val;
            top--;
        }
        stack[++top] = i;
        curr = curr->next;
        i++;
    }

    *returnSize = i;
    free(values);
    return res;
}

int main() {
	// Example usage
	struct ListNode* head = malloc(sizeof(struct ListNode));
	head->val = 2;
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 1;
	head->next->next = malloc(sizeof(struct ListNode));
	head->next->next->val = 5;
	head->next->next->next = NULL;

	int returnSize;
	int* result = nextLargerNodes(head, &returnSize);

	for (int i = 0; i < returnSize; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);
	free(head->next->next);
	free(head->next);
	free(head);

	return 0;
}
