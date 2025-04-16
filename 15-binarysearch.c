#include<stdio.h>
#include<stdlib.h>
int bs(int a[], int n, int t) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == t) return m;
        if (a[m] < t) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
int main() {
    int a[] = {2, 3, 4, 10, 40};
    int n = sizeof(a) / sizeof(a[0]);
    int t = 10;
    int res = bs(a, n, t);
    if (res != -1) printf("Found at %d\n", res);
    else printf("Not found\n");
    return 0;
}
