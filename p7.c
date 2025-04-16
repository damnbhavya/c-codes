#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char id[10];
    int d;
    int p;
} Job;
int cmp(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->p - j1->p;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
void jobSeq(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), cmp);
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].d > maxD)
            maxD = jobs[i].d;
    }
    int dp[MAX + 1];
    int slot[MAX + 1];
    memset(dp, 0, sizeof(dp));
    memset(slot, -1, sizeof(slot));
    for (int i = 0; i < n; i++) {
        for (int t = jobs[i].d; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = i;
                dp[t] = dp[t - 1] + jobs[i].p;
                break;
            }
        }
    }
    printf("Scheduled Jobs: ");
    int totalP = 0;
    for (int i = 1; i <= maxD; i++) {
        if (slot[i] != -1) {
            printf("%s ", jobs[slot[i]].id);
            totalP += jobs[slot[i]].p;
        }
    }
    printf("\nTotal Profit: %d\n", totalP);
}
int main() {
    Job jobs[] = {
        {"J1", 2, 60},
        {"J2", 1, 100},
        {"J3", 3, 20},
        {"J4", 2, 40},
        {"J5", 1, 20}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSeq(jobs, n);
    return 0;
}
