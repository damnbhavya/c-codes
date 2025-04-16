#include <stdio.h>
#include <limits.h>
#define MAX 16
#define INF INT_MAX
int n;
int d[MAX][MAX];
int dp[MAX][1 << MAX];
int tsp(int p, int v) {
    if (v == (1 << n) - 1) {
        return d[p][0] ? d[p][0] : INF;
    }
    if (dp[p][v] != -1) {
        return dp[p][v];
    }
    int ans = INF;
    for (int c = 0; c < n; c++) {
        if (!(v & (1 << c)) && d[p][c]) {
            int newAns = d[p][c] + tsp(c, v | (1 << c));
            if (newAns < ans)
                ans = newAns;
        }
    }
    return dp[p][v] = ans;
}
int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            scanf("%d", &d[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = -1;
    int res = tsp(0, 1);
    if (res == INF)
        printf("No solution exists.\n");
    else
        printf("The minimum cost is %d\n", res);
    return 0;
}
