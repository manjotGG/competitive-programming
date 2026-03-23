//dynamic approach to solve the stone game problem.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int stoneGame(int* piles, int pilesSize) {
    int n = pilesSize;

    // Allocate 2D DP array
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Base case: single pile
    for (int i = 0; i < n; i++) {
        dp[i][i] = piles[i];
    }

    // Fill DP table
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            int takeLeft = piles[i] - dp[i + 1][j];
            int takeRight = piles[j] - dp[i][j - 1];

            dp[i][j] = (takeLeft > takeRight) ? takeLeft : takeRight;
        }
    }

    int result = dp[0][n - 1] > 0;

    // Free memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

//Optimal approach to solve the stone game problem.
bool stoneGame(int* piles, int pilesSize) {
    return true;
}

