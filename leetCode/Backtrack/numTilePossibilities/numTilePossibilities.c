#include <stdio.h>
#include <string.h>

void backtrack(int* count, int* result) {
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            (*result)++;
            count[i]--;
            backtrack(count, result);
            count[i]++;
        }
    }
}

int numTilePossibilities(char* tiles) {
    int count[26] = {0};
    int size = strlen(tiles);
    for (int i = 0; i < size; i++) {
        count[tiles[i] - 'A']++;
    }
    int result = 0;
    backtrack(count, &result);
    return result;
}

int main() {
    char tiles[] = "AAB";
    printf("%d\n", numTilePossibilities(tiles));
    return 0;
}
