#include <stdio.h>

void ArrayC(int arr[], int n) {
    int i, j, min;
    int ans[n];
    ans[0] = -1;
    for(i = 1; i < n; i++) {
        min = -1;
        for(j = i - 1; j >= 0; j--) {
            if(arr[j] <= arr[i]) {
                min = arr[j];
                break;
            }
        }
        ans[i] = min;
    }
    for(i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    ArrayC(arr, n);
    return 0;
}
