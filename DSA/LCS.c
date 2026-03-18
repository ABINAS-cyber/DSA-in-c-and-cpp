#include <stdio.h>
#include <string.h>

// Function to compute LCS length and fill DP table
int lcs(char *X, char *Y, int m, int n, int dp[m+1][n+1]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[m][n];
}

// Function to print the actual LCS using backtracking
void printLCS(char *X, char *Y, int m, int n, int dp[m+1][n+1]) {
    int index = dp[m][n];
    char lcsStr[index + 1];
    lcsStr[index] = '\0'; // Null terminate

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcsStr[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcsStr);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";
    int m = strlen(X);
    int n = strlen(Y);

    int dp[m+1][n+1]; // DP table

    int length = lcs(X, Y, m, n, dp);
    printf("Length of LCS: %d\n", length);

    printLCS(X, Y, m, n, dp);

    return 0;
}
