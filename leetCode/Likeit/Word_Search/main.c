#include <stdio.h>
#include <string.h>

#define N 3
#define M 4

int search(char str[N][M], int i, int j, const char *ptr, int index, int visited[N][M]) {
    if (index == strlen(ptr)) return 1;
    if (i < 0 || i >= N || j < 0 || j >= M || visited[i][j] || str[i][j] != ptr[index]) return 0;

    visited[i][j] = 1;

    int found = search(str, i-1, j, ptr, index+1, visited) ||
                search(str, i+1, j, ptr, index+1, visited) ||
                search(str, i, j-1, ptr, index+1, visited) ||
                search(str, i, j+1, ptr, index+1, visited);

    visited[i][j] = 0;

    return found;
}

int ft_Word_Search(char str[N][M], const char *ptr) {
    int visited[N][M] = {0};
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (str[i][j] == ptr[0] && search(str, i, j, ptr, 0, visited)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char str[N][M] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    const char *ptr = "SEE";
    int result = ft_Word_Search(str, ptr);
    printf("%s\n", result ? "True" : "False");
    return 0;
}
