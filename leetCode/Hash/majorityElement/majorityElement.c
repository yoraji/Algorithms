#include<stdio.h>

int majorityElement(int* nums, int numsSize) {
	int num = 0;
	int counter = 0;
	for(int i=0; i< numsSize;i++){
		if(counter == 0)
		{
			num = nums[i];
			counter++;
		}else if(counter == nums[i])
		{
			counter++;
		}else
			counter--;
	}
	return num;
}

int main()
{
	int nums[5] = {3,2,1,3,3};
	int result = majorityElement(nums,5);
	printf("%d", result);
}
