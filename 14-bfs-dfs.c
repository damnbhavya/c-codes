#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void BFS(int adj[MAX][MAX], int n, int start) {
    int vis[MAX] = {0};
    int q[MAX];
    int f = 0, r = -1;
    printf("BFS traversal starting from node %d: ", start);
    vis[start] = 1;
    q[++r] = start;
    while (f <= r) {
        int curr = q[f++];
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !vis[i]) {
                vis[i] = 1;
                q[++r] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int adj[MAX][MAX], int n, int start) {
    int vis[MAX] = {0};
    int s[MAX];
    int t = -1;
    printf("DFS traversal starting from node %d: ", start);
    s[++t] = start;
    while (t >= 0) {
        int curr = s[t--];
        if (!vis[curr]) {
            printf("%d ", curr);
            vis[curr] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !vis[i]) {
                s[++t] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &e);
    int adj[MAX][MAX] = {0};
    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < e; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    int start;
    printf("Enter the starting node for BFS and DFS: ");
    scanf("%d", &start);
    BFS(adj, n, start);
    DFS(adj, n, start);
    return 0;
}

