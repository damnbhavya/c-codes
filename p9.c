#include <stdio.h>
#include <stdbool.h>
#define N 8

int b[N][N];

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", b[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int r, int c) {
    for (int i = 0; i < r; i++)
        if (b[i][c])
            return false;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return false;
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
        if (b[i][j])
            return false;
    return true;
}

bool solveNQueens(int r) {
    if (r == N) {
        printBoard();
        return true;
    }
    for (int c = 0; c < N; c++) {
        if (isSafe(r, c)) {
            b[r][c] = 1;
            if (solveNQueens(r + 1))
                return true;  // stop after the first solution
            b[r][c] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b[i][j] = 0;

    if (!solveNQueens(0))
        printf("No solution exists.\n");

    return 0;
}
