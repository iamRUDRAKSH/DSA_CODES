#include<stdio.h>

int main() {
    // Initiation of array
    int n;
    printf("How many values: ");
    scanf("%d", &n);
    int A[n];
    
    printf("Enter values in the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    // Sorting the array using selection sort
    int i, j, minIndex, temp;
    for(i = 0; i < n - 1; i++) {
        minIndex = i;  // Initially assume the min element is at index i
        
        // Find the minimum element in unsorted array
        for(j = i + 1; j < n; j++) {
            if(A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the element at index i
        if(minIndex != i) {
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }

    // Print the sorted array
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}