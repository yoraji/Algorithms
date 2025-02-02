#include <stdio.h>
#include <stdbool.h>

bool check(int* nums, int numsSize) {
    int pivot = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            pivot = i;
            break;
        }
    }
    if (pivot == 0)
        return true;
    for (int i = pivot + 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    if (nums[numsSize - 1] > nums[0])
        return false;
    return true;
}

int main()
{
	int arr[] = {3,4,5,1,2};
	printf("%d",check(arr, 5));
}
