#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int distributeCandies(int* candyType, int candyTypeSize) {
    int maxCandies = candyTypeSize / 2;
    qsort(candyType, candyTypeSize, sizeof(int), compare);
    int uniqueCount = 1;
    for (int i = 1; i < candyTypeSize; i++) {
        if (candyType[i] != candyType[i - 1]) {
            uniqueCount++;
        }
    }
    return (uniqueCount < maxCandies) ? uniqueCount : maxCandies;
}

int main() {
    int candyType1[] = {1, 1, 2, 2, 3, 3};
    int size1 = sizeof(candyType1) / sizeof(candyType1[0]);
    int result1 = distributeCandies(candyType1, size1);
    printf("Example 1 Output: %d\n", result1);

    int candyType2[] = {1, 1, 2, 3};
    int size2 = sizeof(candyType2) / sizeof(candyType2[0]);
    int result2 = distributeCandies(candyType2, size2);
    printf("Example 2 Output: %d\n", result2);

    int candyType3[] = {6, 6, 6, 6};
    int size3 = sizeof(candyType3) / sizeof(candyType3[0]);
    int result3 = distributeCandies(candyType3, size3);
    printf("Example 3 Output: %d\n", result3);

    return 0;
}
