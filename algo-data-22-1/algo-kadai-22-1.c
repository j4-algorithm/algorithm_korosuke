#include "matrix.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int SolveChainMatrixMultiplicationProblem(Matrix matrices[MAX_NUM_MATRIX], size_t nmemb) {
    int dp[MAX_NUM_MATRIX+1][MAX_NUM_MATRIX+1] = {0};
    int p[MAX_NUM_MATRIX+1];
    p[0] = matrices[0].numRow;
    for (int i = 0; i < nmemb; i++) {
        p[i+1] = matrices[i].numCol;
    
    for (int length = 2; length <= nmemb; length++) {
        for (int i = 1; i <= nmemb - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    }

    return dp[1][nmemb];
}


int main(void){
    size_t nmemb = 0;
    scanf("%zu", &nmemb);

    Matrix matrix[MAX_NUM_MATRIX];
    for (size_t i = 0; i < nmemb; i++) {
        scanf("%d %d", &matrix[i].numRow, &matrix[i].numCol);
    }

    int result = SolveChainMatrixMultiplicationProblem(matrix, nmemb);
    if (result != -1) {
        printf("最小のスカラー乗算回数: %d\n", result);
    } else {
        printf("エラー\n");
    }

    return 0;
}
