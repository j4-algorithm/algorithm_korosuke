#include <stdio.h>

#define MAX_ITEMS 10
#define MAX_WEIGHT 50

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int knapsack(int n, int weights[], int values[], int capacity) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    scanf("%d", &n);

    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }

    int max_value = knapsack(n, weights, values, MAX_WEIGHT);
    printf("最大価値: %d\n", max_value);

    return 0;
}
