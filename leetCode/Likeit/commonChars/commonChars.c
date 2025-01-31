#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** commonChars(char** words, int wordsSize, int* returnSize) {
    int hash[26] = {0};
    int minCount[26] = {0};

    for (int i = 0; words[0][i]; i++) {
        minCount[words[0][i] - 'a']++;
    }

    for (int i = 1; i < wordsSize; i++) {
        int tempCount[26] = {0};
        for (int j = 0; words[i][j]; j++) {
            tempCount[words[i][j] - 'a']++;
        }
        
	for (int k = 0; k < 26; k++) {
            if (tempCount[k] < minCount[k]) {
                minCount[k] = tempCount[k];
            }
        }
    }

    *returnSize = 0;
    for (int i = 0; i < 26; i++) {
        *returnSize += minCount[i];
    }

    char** result = (char**)malloc(*returnSize * sizeof(char*));
    int index = 0;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < minCount[i]; j++) {
            result[index] = (char*)malloc(2 * sizeof(char));
            result[index][0] = 'a' + i;
            result[index][1] = '\0';
            index++;
        }
    }

    return result;
}

int main() {
    char* words[] = {"bella", "label", "roller"};
    int wordsSize = 3;
    int returnSize;
    char** result = commonChars(words, wordsSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}
