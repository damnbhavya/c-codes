#include <stdio.h>
int bS(int a[], int l, int h, int t) {
    if (h >= l) {
        int m = l + (h - l) / 2;
        if (a[m] == t)
            return m;
        if (a[m] > t)
            return bS(a, l, m - 1, t);
        return bS(a, m + 1, h, t);
    }
    return -1;
}
int main() {
    int a[] = {2, 4, 10, 23, 45, 66, 89};
    int n = sizeof(a) / sizeof(a[0]);
    int t = 23;
    int res = bS(a, 0, n - 1, t);
    if (res != -1)
        printf("%d found at %d\n", t, res);
    else
        printf("%d not found\n", t);
    return 0;
}


