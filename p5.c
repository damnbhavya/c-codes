#include <stdio.h>
struct item {
    int w;
    int v;
};
void swap(struct item *a, struct item *b) {
    struct item t = *a;
    *a = *b;
    *b = t;
}
void sortitems(struct item it[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float r1 = (float)it[i].v / it[i].w;
            float r2 = (float)it[j].v / it[j].w;
            if (r1 < r2) {
                swap(&it[i], &it[j]);
            }
        }
    }
}
float fknapsack(struct item it[], int n, int c) {
    sortitems(it, n);
    float tv = 0.0;
    for (int i = 0; i < n; i++) {
        if (c >= it[i].w) {
            c -= it[i].w;
            tv += it[i].v;
        } else {
            tv += it[i].v * ((float)c / it[i].w);
            break;
        }
    }
    return tv;
}
int main() {
    struct item it[] = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int n = sizeof(it) / sizeof(it[0]);
    int c = 50;
    float mv = fknapsack(it, n, c);
    printf("Maximum value in Knapsack = %.2f\n", mv);
    return 0;
}
