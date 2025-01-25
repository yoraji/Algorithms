#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int n, int leftCount, int rightCount, char *output, int outputSize,
               char ***result, int *resultSize, int *resultCapacity) {
    if (leftCount >= n && rightCount >= n) {
        char *outputStr = malloc((outputSize + 1) * sizeof(char));
        memcpy(outputStr, output, outputSize * sizeof(char));
        outputStr[outputSize] = '\0';

        if (*resultSize >= *resultCapacity) {
            *resultCapacity *= 2;
            *result = realloc(*result, *resultCapacity * sizeof(char *));
        }
        (*result)[*resultSize] = outputStr;
        (*resultSize)++;
        return;
    }

    if (leftCount < n) {
        output[outputSize] = '(';
        backtrack(n, leftCount + 1, rightCount, output, outputSize + 1, result, resultSize, resultCapacity);
    }


    if (rightCount < leftCount) {
        output[outputSize] = ')';
        backtrack(n, leftCount, rightCount + 1, output, outputSize + 1, result, resultSize, resultCapacity);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    int resultCapacity = 16;
    int resultSize = 0;
    char **result = malloc(resultCapacity * sizeof(char *));
    char *output = malloc(2 * n * sizeof(char)); 
    backtrack(n, 0, 0, output, 0, &result, &resultSize, &resultCapacity);

    free(output);
    *returnSize = resultSize;
    return result;
}

void freeResult(char **result, int resultSize) {
    for (int i = 0; i < resultSize; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int n = 3;
    int returnSize;
    char **result = generateParenthesis(n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    freeResult(result, returnSize);
    return 0;
}
