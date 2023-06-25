#include <stdio.h>
#include <stdlib.h>

void ArrayC(int arr[], int n) {
    int *ns = (int *) malloc(n * sizeof(int)); // allocate memory for nearest smaller values
    int stack[n]; // use a stack to keep track of previous elements with smaller values
    int top = -1; // initialize stack top index to -1
    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[stack[top]] >= arr[i]) {
            top--; // pop elements with larger or equal values
        }
        if (top >= 0) {
            ns[i] = arr[stack[top]]; // set nearest smaller value
        } else {
            ns[i] = -1; // no smaller value found
        }
        stack[++top] = i; // push current element index to stack
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ns[i]); // print nearest smaller value list
    }
    free(ns); // deallocate memory for nearest smaller values
}

int main() {
    int arr[] = {5, 2, 8, 3, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    ArrayC(arr, n);
    return 0;
}
