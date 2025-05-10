// Bubble Sort Implementation in C
#include <stdio.h>

int main() {
    int n;

    // Prompt user to enter number of elements
    printf("How many values: ");
    scanf("%d", &n);

    int A[n];

    // Input array elements
    printf("Enter values in the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Bubble Sort Algorithm
    // Outer loop runs n-1 times
    for (int i = 0; i < n - 1; i++) {

        // Inner loop for comparing adjacent elements
        // Stops at n-i-1 to avoid checking already sorted elements
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j + 1] < A[j]) {
                // Swap if the right element is smaller than the left
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}