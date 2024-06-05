#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int s[50][50]; // Board to visualize the solution

void display(int m[], int n) {
    register int i, j;

    // Initialize the board with 0
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            s[i][j] = 0;

    // Place queens on the board based on array m
    for (i = 0; i < n; i++)
        s[i][m[i]] = 1;

    // Print the board
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s[i][j])
                printf("Q ");
            else
                printf("X ");
        }
        printf("\n");
    }
    printf("\n");
    exit(0);
}

int place(int m[], int k) {
    int i;
    for (i = 0; i < k; i++) {
        if (m[i] == m[k] || (abs(m[i] - m[k]) == abs(i - k)))
            return 0;
    }
    return 1;
}

int main() {
    int m[25], n, k;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    printf("The solution to the queens problem is:\n");

    n--; // Adjust for zero-indexing

    for (m[0] = 0, k = 0; k >= 0; m[k] += 1) {
        while (m[k] <= n && !place(m, k))
            m[k] += 1;
        if (m[k] <= n) {
            if (k == n) {
                display(m, n + 1);
            } else {
                k++;
                m[k] = -1; // Reset the next queen position
            }
        } else {
            k--; // Backtrack
        }
    }

    printf("No solution found.\n");

    return 0;
}