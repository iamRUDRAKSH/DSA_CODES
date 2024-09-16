#include <iostream>
#include <string>
using namespace std;

// Merge function to combine two sorted subarrays into a single sorted array
void merge(int *arr, int s, int e) {
    int mid = (s + e) / 2; // Find the middle point of the array
    int *left = new int[mid - s + 1]; // Create temporary array for left subarray
    int *right = new int[e - mid]; // Create temporary array for right subarray

    // Copy data to temporary arrays
    for (int i = s; i <= mid; i++) {
        left[i - s] = arr[i];
    }
    for (int j = mid + 1; j <= e; j++) {
        right[j - mid - 1] = arr[j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = s; // Initialize indices for left, right, and original arrays
    while (i < (mid - s + 1) && j < (e - mid)) { // Use correct sizes of left and right
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of left array
    while (i < (mid - s + 1)) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy any remaining elements of right array
    while (j < (e - mid)) {
        arr[k] = right[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    delete[] left;
    delete[] right;
}

// Merge sort function to recursively divide the array and then merge
void merge_sort(int *arr, int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        merge_sort(arr, s, mid); // Sort the left half
        merge_sort(arr, mid + 1, e); // Sort the right half
        merge(arr, s, e); // Merge the sorted halves
    }    
}

int main() {
    int arr[] = {72, 12, 62, 82, 92, 42, 52, 2}; // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    merge_sort(arr, 0, n - 1); // Perform merge sort
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the sorted array
    } 
    return 0;
}
