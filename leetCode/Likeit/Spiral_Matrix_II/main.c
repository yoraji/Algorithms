#include <stdlib.h>
#include <stdio.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **arr = malloc(sizeof(int*) * n);
    if (!arr) return NULL;
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    if (!*returnColumnSizes) {
        free(arr);
        return NULL;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = malloc(sizeof(int) * n);
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            free(*returnColumnSizes);
            return NULL;
        }
        (*returnColumnSizes)[i] = n;
    }
    int counter = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1; 
    while(left <= right && top <= bottom) {
        for(int i = left; i <= right; i++) // left --> right
            arr[top][i] = counter++;
        top++;
        for(int i = top; i <= bottom; i++)  // top --> bottom 
            arr[i][right] = counter++;
        right--;
        for(int i = right; i >= left; i--) // right --> left
            arr[bottom][i] = counter++;
        bottom--;
        for(int i = bottom; i >= top; i--) // bottom --> top
            arr[i][left] = counter++;
        left++;
    }
    return arr;
}

int main() {
    int n = 10;
    int returnSize;
    int* returnColumnSizes;
    int** result = generateMatrix(n, &returnSize, &returnColumnSizes);
    if (result) {
        for (int i = 0; i < returnSize; i++) {
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < returnSize; i++) {
            free(result[i]);
        }
        free(result);
        free(returnColumnSizes);
    }    return 0;
}