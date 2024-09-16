#include<iostream>
using namespace std;

// Function to perform insertion sort on an array
int* insertion_sort(int* A, int n) {
    int i, j;
    // Traverse from the second element to the end
    for (i = 1; i < n; i++) {
        int t = A[i]; // Element to be inserted
        j = i - 1;

        // Move elements of A[0..i-1] that are greater than t to one position ahead of their current position
        while (j >= 0 && A[j] > t) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = t; // Insert the element at its correct position
    }
    return A; // Return the sorted array
}

// Function to print array elements
void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {99, 88, 77, 55, 66, 44, 33, 11, 112, 91, 3, 1}; // Array to be sorted
    int n = sizeof(A) / sizeof(A[0]); // Calculate the number of elements in the array

    insertion_sort(A, n); // Sort the array
    print_array(A, n); // Print the sorted array

    return 0;
}
