#include <stdio.h>
void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}
int part(int arr[], int l, int h) {
    int p = arr[h];
    int i = (l - 1);
    for (int j = l; j < h; j++) {
        if (arr[j] <= p) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void qSort(int arr[], int l, int h) {
    if (l < h) {
        int pi = part(arr, l, h);
        qSort(arr, l, pi - 1);
        qSort(arr, pi + 1, h);
    }
}
void printArr(int arr[], int sz) {
    for (int i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArr(arr, n);
    qSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArr(arr, n);
    return 0;
}
