#include <stdio.h>

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    /*
     * This loop alternates between:
     * - pushing the maximum to the end (even i)
     * - pushing the minimum to the front (odd i)
     * Each step reduces the effective range from both sides.
     */
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            // Even iteration → place max at rightmost unsorted position
            int max = A[i % 2], imax = i % 2;
            for (int j = 1; j < n - (i / 2); j++) {
                if (A[j] > max) {
                    max = A[j];
                    imax = j;
                }
            }
            // Swap max with last unsorted element
            int temp = A[imax];
            A[imax] = A[n - 1 - (i / 2)];
            A[n - 1 - (i / 2)] = temp;
        } else {
            // Odd iteration → place min at leftmost unsorted position
            int min = A[n - 2 - (i / 2)], imin = n - 2 - (i / 2);
            for (int j = n - 2 - (i / 2); j >= i / 2; j--) {
                if (A[j] < min) {
                    min = A[j];
                    imin = j;
                }
            }
            // Swap min with first unsorted element
            int temp = A[imin];
            A[imin] = A[i / 2];
            A[i / 2] = temp;
        }

        // Print array after each pass
        for (int k = 0; k < n; k++) {
            printf("%d\t", A[k]);
        }
        printf("\n");
    }

    return 0;
}