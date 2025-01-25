#include <stdio.h>
#include <stdlib.h>


void generateSubsets(int* nums, int numsSize);
void backtrack(int* nums, int numsSize, int start, int* tempSet, int tempSize);
void printSubset(int* subset, int size);

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    generateSubsets(nums, numsSize);

    return 0;
}

void generateSubsets(int* nums, int numsSize) {
    int* tempSet = (int*)malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, 0, tempSet, 0);
    free(tempSet);
}

void backtrack(int* nums, int numsSize, int start, int* tempSet, int tempSize) {
    printSubset(tempSet, tempSize);
    for (int i = start; i < numsSize; ++i) {
        tempSet[tempSize] = nums[i];

        backtrack(nums, numsSize, i + 1, tempSet, tempSize + 1);

	tempSet[tempSize] = nums[i];
    }
}

void printSubset(int* subset, int size) {
    printf("{ ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

