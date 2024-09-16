#include<iostream>
using namespace std;

// Function to find the maximum value in the array
int find_max(int *a, int n) {
    int max = a[0]; // Initialize max to the first element
    for (int i = 1; i < n; i++) { // Iterate through the rest of the array
        if (a[i] > max) // Update max if a larger value is found
            max = a[i];
    }
    return max; // Return the maximum value
}

// Function to perform Radix Sort on the array
void radix_sort(int *a, int n) {
    int max = find_max(a, n); // Find the maximum value in the array
    // Process each digit (units, tens, hundreds, etc.)
    for (int exp = 1; (max / exp) > 0; exp *= 10) {
        int output[n]; // Output array to hold the sorted values for the current digit
        int count[10] = {0}; // Count array to store count of occurrences for each digit

        // Store count of occurrences of each digit in count[]
        for (int i = 0; i < n; i++) {
            int digit = (a[i] / exp) % 10; // Extract the digit at the current place value
            count[digit]++; // Increment the count for this digit
        }

        // Update count[i] to contain actual position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1]; // Accumulate counts to get positions
        }

        // Build the output array using the count array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (a[i] / exp) % 10; // Extract the digit at the current place value
            output[count[digit] - 1] = a[i]; // Place the element in the correct position
            count[digit]--; // Decrement the count for this digit
        }

        // Copy the output array to the original array
        for (int i = 0; i < n; i++) {
            a[i] = output[i];
        }
    }
}

int main() {
    int a[] = {12, 5, 7, 8, 19, 34, 24, 55, 11, 3}; // Array to be sorted
    int n = sizeof(a) / sizeof(int); // Calculate the number of elements
    radix_sort(a, n); // Perform radix sort
    for (int i = 0; i < n; i++) // Print the sorted array
        cout << a[i] << " ";
    return 0;
}
