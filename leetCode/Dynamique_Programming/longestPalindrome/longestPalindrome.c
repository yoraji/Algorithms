#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(const char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char* longestPalindrome(const char* s) {
    int length = strlen(s);
    if (length == 0) {
        return NULL;
    }
    
    char *longest = malloc((length + 1) * sizeof(char));
    if (!longest) {
        return NULL;
    }
    
    int longestLength = 0;
    
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (isPalindrome(s, i, j)) {
                int currentLength = j - i + 1;
                if (currentLength > longestLength) {
                    longestLength = currentLength;
                    strncpy(longest, s + i, currentLength);
                    longest[currentLength] = '\0'; // Null-terminate the string
                }
            }
        }
    }
    
    return longest;
}

int main() {
    char s[] = "babad";
    char *result = longestPalindrome(s);
    if (result) {
        printf("Longest palindrome: %s\n", result);
        free(result); // Free allocated memory
    } else {
        printf("No palindrome found.\n");
    }
    return 0;
}

