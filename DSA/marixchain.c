#include <stdio.h>
#include <limits.h>
#include <string.h>

// Function to print the optimal parenthesization
void printOptimalParenthesis(int i, int j, int n, int bracket[n][n], char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printOptimalParenthesis(i, bracket[i][j], n, bracket, name);
    printOptimalParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    printf(")");
}

// Function to solve Matrix Chain Multiplication
void matrixChainOrder(int p[], int n) {
    long long m[n][n];       // m[i][j] = minimum cost
    int bracket[n][n];       // bracket[i][j] = index where split occurs

    // Initialize diagonal to zero (cost of multiplying one matrix is zero)
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) {
                long long q = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %lld\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    char name = 'A';
    printOptimalParenthesis(1, n - 1, n, bracket, &name);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of matrices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int p[n + 1];
    printf("Enter dimensions (n+1 integers): ");
    for (int i = 0; i <= n; i++) {
        if (scanf("%d", &p[i]) != 1 || p[i] <= 0) {
            printf("Invalid dimension. Please enter positive integers only.\n");
            return 1;
        }
    }

    matrixChainOrder(p, n + 1);
    return 0;
}
