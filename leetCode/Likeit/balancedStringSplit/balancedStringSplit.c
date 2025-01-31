i#include <stdio.h>

int balancedStringSplit(char* s) {
    if (s == NULL || s[0] == '\0') {
        return 0; 
    }
    char c1 = s[0];
    char c2 = '\0';

    for (int i = 1; s[i]; i++) {
        if (s[i] != c1) {
            c2 = s[i];
            break;
        }
    }
    if (c2 == '\0') {
        return 0;
    }

    int counter1 = 0; 
    int counter2 = 0;
    int result = 0; 

    for (int i = 0; s[i]; i++) {
        if (s[i] == c1) {
            counter1++;
        } else if (s[i] == c2) {
            counter2++;
        }
        if (counter1 == counter2) {
            result++;
            counter1 = 0;
            counter2 = 0;
        }
    }

    return result;
}

int main() {
    char s[] = "RLRRLLRLRL";
    int result = balancedStringSplit(s);
    printf("Number of balanced substrings: %d\n", result); // Output: 4

    return 0;
}
