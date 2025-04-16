#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int w;
    int v;
    double r;
} I;
typedef struct {
    int l;
    int p;
    int w;
    double b;
} N;
int max(int a, int b) {
    return a > b ? a : b;
}
int cmp(const void* a, const void* b) {
    I* i1 = (I*)a;
    I* i2 = (I*)b;
    if (i2->r > i1->r) return 1;
    else return -1;
}
double bound(N u, int n, int W, I items[]) {
    if (u.w >= W) return 0;
    double pb = (double)u.p;
    int j = u.l + 1;
    int tw = u.w;
    while ((j < n) && (tw + items[j].w <= W)) {
        tw += items[j].w;
        pb += items[j].v;
        j++;
    }
    if (j < n)
        pb += (W - tw) * items[j].r;
    return pb;
}
int knapsack(int W, I items[], int n) {
    qsort(items, n, sizeof(I), cmp);
    N u, v;
    int mp = 0;
    N q[1000];
    int f = 0, r = 0;
    v.l = -1;
    v.p = 0;
    v.w = 0;
    v.b = bound(v, n, W, items);
    q[r++] = v;
    while (f < r) {
        v = q[f++];
        if (v.l == n - 1)
            continue;
        u.l = v.l + 1;
        u.w = v.w + items[u.l].w;
        u.p = v.p + items[u.l].v;
        if (u.w <= W && u.p > mp)
            mp = u.p;
        u.b = bound(u, n, W, items);
        if (u.b > mp)
            q[r++] = u;
        u.w = v.w;
        u.p = v.p;
        u.b = bound(u, n, W, items);
        if (u.b > mp)
            q[r++] = u;
    }
    return mp;
}
int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    I items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].w, &items[i].v);
        items[i].r = (double)items[i].v / items[i].w;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int mp = knapsack(W, items, n);
    printf("Maximum profit: %d\n", mp);
    return 0;
}
