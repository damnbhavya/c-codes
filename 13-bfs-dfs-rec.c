#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void BFSRec(int adj[MAX][MAX], int vis[MAX],
            int q[MAX], int f, int r) {
    if (f > r) {
        return;
    }
    int curr = q[f];
    printf("%d ", curr);
    f++;
    for (int i = 0; i < MAX; i++) {
        if (adj[curr][i] == 1 && !vis[i]) {
            vis[i] = 1;
            q[++r] = i;
        }
    }
    BFSRec(adj, vis, q, f, r);
}
void BFS(int adj[MAX][MAX], int n, int start) {
    int vis[MAX] = {0};
    int q[MAX];
    int f = 0, r = -1;
    printf("BFS from node %d: ", start);
    vis[start] = 1;
    q[++r] = start;
    BFSRec(adj, vis, q, f, r);
    printf("\n");
}
void DFSRec(int adj[MAX][MAX], int vis[MAX], int curr) {
    vis[curr] = 1;
    printf("%d ", curr);
    for (int i = 0; i < MAX; i++) {
        if (adj[curr][i] == 1 && !vis[i]) {
            DFSRec(adj, vis, i);
        }
    }
}
void DFS(int adj[MAX][MAX], int n, int start) {
    int vis[MAX] = {0};
    printf("DFS from node %d: ", start);
    DFSRec(adj, vis, start);
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


