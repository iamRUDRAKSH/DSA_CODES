#include<stdio.h>

int main() {
    int n;
    printf("How many values : ");
    scanf("%d", &n);
    int A[n];
    printf("Enter values in the array :\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Insertion Sort
    for(int i = 1; i < n; i++) {  // Start from index 1
        int temp = A[i];           // Key value to insert
        int j = i - 1;

        // Move elements of A[0..i-1] that are greater than temp to one position ahead
        while(j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;  // Place the key value at the correct position

        // Print the array after each pass of insertion
        for(int k = 0; k < n; k++) {
            printf("%d\t", A[k]);
        }
        printf("\n");
    }
    return 0;
}