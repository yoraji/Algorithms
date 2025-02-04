#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int maxAscendingSum(int* nums, int numsSize) {
	int res = 0;
	int count = nums[0];
	int max = INT_MIN;
	for(int i=1;i<numsSize;i++)
	{
		if(nums[i] > nums[i-1])
			count += nums[i];
		else
		{
			if(count > res)
				res = count;
			count = nums[i];
		}
	}
	if(count > res)
		res = count;
	return res;
}

int main() {
    int nums[] = {10, 20, 30, 5, 10, 50};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", maxAscendingSum(nums, size));
    return 0;
}
