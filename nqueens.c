#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum board size

int board[MAX];
int count = 0;

// Function to print a solution
void printSolution(int n) {
    printf("Solution %d: ", ++count);
    for (int i = 1; i <= n; i++) {
        printf("%d ", board[i]);  // column position of queen in each row
    }
    printf("\n");
}

// Function to check if a queen can be placed safely
int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check same column or diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

// Recursive function to place queens
void placeQueens(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;  // place queen
            if (row == n)
                printSolution(n);  // all queens placed
            else
                placeQueens(row + 1, n);  // place rest
        }
    }
}

int main() {
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of queens! Please enter between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nAll possible solutions for %d-Queens problem:\n", n);
    placeQueens(1, n);

    if (count == 0)
        printf("No solutions exist for %d queens.\n", n);

    return 0;
}
