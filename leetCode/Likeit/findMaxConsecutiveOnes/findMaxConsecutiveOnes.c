#include <stdio.h>
#include <limits.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int nm = INT_MIN;
    int result = 0;
    for(int i=0;i < numsSize;i++)
    {
        if (nums[i] == 1)
            result++;
        else{
            if(result >= nm)
                nm = result;
            result = 0;
        }
    }
    if(result >= nm)
        nm = result;
    return nm;
}
int main() {
    int nums[] = {1, 1, 0, 1, 1, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums, size);
    printf("Max consecutive ones: %d\n", maxConsecutiveOnes);
    return 0;
}
