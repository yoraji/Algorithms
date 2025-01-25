#include <stdio.h>

int backtracking(int arr[], int target, int result, int size, int index) {
    if (result == target) return 1;
    if (result > target) return 0;
    for (int i = 0; i < size; i++) {
        if(backtracking(arr, target, result + arr[i], size,index)){
		index++;
		printf("%d ",index);
		return 1;
	}
    }
    return 0;
}

int main() {
    int arr[] = {3,4,5};
    int target = 16;
    int size = 3;
    printf("Combinations to reach the target %d:\n", target);
    int found = 0;
    found = backtracking(arr, target, 0, size,0);
    if (!found) {
        printf("No valid combinations found.\n");
    }
    
    return 0;
}

