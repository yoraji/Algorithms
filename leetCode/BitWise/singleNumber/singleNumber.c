#include<stdio.h>
#include<stdlib.h>

/*
 *      input Bits "XOR";
 *      ----------------
 *         0 ^ 0 = 0
 *         0 ^ 1 = 1
 *         1 ^ 0 = 1
 *         1 ^ 1 = 0
 *     -----------------
 */

int signalNumber(int *nums, int size){
    int val = 0;
    for(int i=0;i<size;i++){
        val = nums[i]^val;
    }
    return val;
}

int main()
{
    int arr[] = {1,2,2,5,1};
    int size =5;
    int result = signalNumber(arr,size);
    printf("%d \n",result);
    return 0;
}
