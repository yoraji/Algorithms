#include <stdio.h>

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
