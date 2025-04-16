#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;
int cmp(const void* a, const void* b) {
    Item* x = (Item*)a;
    Item* y = (Item*)b;
    if (x->ratio < y->ratio) return 1;
    else if (x->ratio > y->ratio) return -1;
    else return 0;
}
int knapsack(Item it[], int n, int cap) {
    qsort(it, n, sizeof(Item), cmp);
    int val = 0, wt = 0;
    for (int i = 0; i < n; i++) {
        if (wt + it[i].weight <= cap) {
            wt += it[i].weight;
            val += it[i].value;
            printf("Item %d (v:%d, w:%d)\n", i + 1, it[i].value, it[i].weight);
        }
    }
    return val;
}
int main() {
    int n, cap;
    printf("Items: ");
    scanf("%d", &n);
    Item it[n];
    printf("Enter v & w:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d v: ", i + 1);
        scanf("%d", &it[i].value);
        printf("Item %d w: ", i + 1);
        scanf("%d", &it[i].weight);
        it[i].ratio = (float)it[i].value / it[i].weight;
    }
    printf("Cap: ");
    scanf("%d", &cap);
    int maxVal = knapsack(it, n, cap);
    printf("Total v: %d\n", maxVal);
    return 0;
}
