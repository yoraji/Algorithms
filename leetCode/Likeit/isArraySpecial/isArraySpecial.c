#include <stdio.h>
#include <stdbool.h>

bool isArraySpecial(int* nums, int numsSize) {
    for(int i = 0; i < numsSize - 1; i++) {
        if((nums[i] + nums[i+1]) % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int test1[] = {1};
    printf("%d\n", isArraySpecial(test1, 1));
    int test2[] = {2, 1, 4};
    printf("%d\n", isArraySpecial(test2, 3));
    int test3[] = {2, 4, 6};
    printf("%d\n", isArraySpecial(test3, 3));
    return 0;
}
