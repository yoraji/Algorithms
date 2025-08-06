#include <stdio.h>
#include <stdlib.h>

// A function to print the board
void printBoard(char **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Using `printf("%c ", ...)` for better formatting
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(char **board, int n, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return 0; // Not safe
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return 0; // Not safe
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return 0; // Not safe
        }
    }
    return 1;
}

int solveNQueens(char **board, int n, int row) {
    if (row == n) {
        return 1; // All queens are placed successfully
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, n, row, col)) {
            board[row][col] = 'Q'; // Place queen
            // Recur to place the rest of the queens
            if (solveNQueens(board, n, row + 1)) {
                return 1;
            }
            board[row][col] = '.'; // Backtrack
        }
    }

    return 0; // No valid position found in this row
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Number of queens must be at least 1.\n");
        return 1;   
    }

    // Allocate the board
    char **board = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        board[i] = malloc(n * sizeof(char));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    // Solve the N-Queens problem
    if (solveNQueens(board, n, 0)) {
        printf("Solution found:\n");
        printBoard(board, n);
    } else {
        printf("No solution exists.\n");
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}