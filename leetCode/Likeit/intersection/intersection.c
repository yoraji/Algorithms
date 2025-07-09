#include <stdio.h>
#include <stdlib.h>

void quicksort(int* arr, int left, int right) {
    if (left >= right)
        return;

    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    i++;
    int tmp = arr[i];
    arr[i] = arr[right];
    arr[right] = tmp;

    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    quicksort(nums1, 0, nums1Size - 1);
    quicksort(nums2, 0, nums2Size - 1);
    int *result = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int i=0;int j=0;int k=0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] > nums2[j])
            j++;
        else {
            if(k == 0 || result[k-1] != nums1[i])
                result[k++] = nums1[i];
            i++;
            j++;
        }
    }
    *returnSize = k;
    return result;
}

int main() {
    int nums1[4] = {1, 2, 2, 1};
    int nums2[2] = {2, 2};
    int returnSize;
    int* result = intersection(nums1, 4, nums2, 2, &returnSize);
    printf("Intersection: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

