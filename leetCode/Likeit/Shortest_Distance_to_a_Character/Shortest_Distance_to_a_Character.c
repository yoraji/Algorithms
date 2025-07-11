#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* shortestToChar(char* s, char c, int* returnSize) {
    int len = strlen(s);
    int *arr = malloc(sizeof(int)*(len));
    int k=0;int saved_index = -1;
    for(int j=0;s[j];j++)
    {
        if(s[j] == c)
        {
            arr[k++] = 0;
            saved_index = j;
        }else {
            arr[k++] = (saved_index == -1) ? len : j - saved_index;
        }
    }
    saved_index = -1;
    for(int j=len-1;j >= 0; j--)
    {
        if(s[j] == c)
            saved_index = j;
        else if (saved_index != -1)
            arr[j] = (arr[j] < saved_index - j ) ? arr[j] : saved_index - j;

    }
    *returnSize = len;
    return arr;
}

int main() {
    char s[] = "loveleetcode";
    char c = 'e';
    int returnSize;
    int* result = shortestToChar(s, c, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    free(result);
    return 0;
}