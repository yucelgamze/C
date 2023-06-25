#include <stdio.h>

void ArrayC(int arr[], int n) {
    int i, j, prev;
    int result[n];
    
    for (i = 0; i < n; i++) {
        prev = -1;
        for (j = i-1; j >= 0; j--) {
            if (arr[j] <= arr[i]) {
                prev = arr[j];
                break;
            }
        }
        result[i] = prev;
    }

    // printing the result array as a space-separated string
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    ArrayC(arr, n);

    return 0;
}
