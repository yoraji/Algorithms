#include <stdlib.h>
#include <stdio.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ptr = malloc(sizeof(int) * numsSize);
    if(ptr == NULL)
        return NULL;
    int j=0;
    for(int i=0; i<numsSize; i++)
    {
        ptr[j++] = nums[nums[i]];
    }
    return (ptr);
}

int main() {
    int nums[] = {5,0,1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = buildArray(nums, numsSize, &returnSize);
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
