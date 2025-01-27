#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *simplifyPath(char *path)
{
    int len = strlen(path);
    char *res = malloc(len + 1); // 1 for null terminator
    if (!res)
        return NULL; // failed allocation

    int *starts = malloc(len * sizeof(int));
    int *ends = malloc(len * sizeof(int)); // Renamed to 'ends' to avoid confusion
    if (!starts || !ends)
    {
        free(res);
        free(starts);
        free(ends);
        return NULL; // failed allocations
    }

    int top = 0;
    int i = 0;
    while (i < len) // iterate through the string
    {
        while (i < len && path[i] == '/') // skip multiple slashes
            i++;
        if (i >= len)
            break;

        int start = i;
        while (i < len && path[i] != '/') // find the end of the current component
            i++;
        int end = i; // mark the ending

        int len_word = end - start;
        if (len_word == 1 && path[start] == '.')
        {
            continue; // ignore '.'
        }
        else if (len_word == 2 && path[start] == '.' && path[start + 1] == '.') // handle '..'
        {
            if (top > 0)
                top--; // go up one level
        }
        else
        {
            starts[top] = start;
            ends[top] = end;
            top++;
        }
    }

    if (top == 0) // if no valid components, return root
    {
        res[0] = '/';
        res[1] = '\0';
    }
    else
    {
        int pos = 0;
        for (int j = 0; j < top; j++)
        {
            res[pos++] = '/';
            for (int k = starts[j]; k < ends[j]; k++)
                res[pos++] = path[k];
        }
        res[pos] = '\0';
    }

    free(starts);
    free(ends);
    return res;
}

int main() {
    // Test cases
    char path1[] = "/a/./b/../../c/";
    char path2[] = "/home//foo/";
    char path3[] = "/../";
    char path4[] = "/";
    char path5[] = "/a/b/c/..";

    // Simplify paths and print results
    char *res1 = simplifyPath(path1);
    printf("Simplified path 1: %s\n", res1);
    free(res1);

    char *res2 = simplifyPath(path2);
    printf("Simplified path 2: %s\n", res2);
    free(res2);

    char *res3 = simplifyPath(path3);
    printf("Simplified path 3: %s\n", res3);
    free(res3);

    char *res4 = simplifyPath(path4);
    printf("Simplified path 4: %s\n", res4);
    free(res4);

    char *res5 = simplifyPath(path5);
    printf("Simplified path 5: %s\n", res5);
    free(res5);

    return 0;
}
