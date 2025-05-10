#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element is found at index mid
        }

        if (arr[mid] < target) {
            left = mid + 1; // Narrow down the search to the right half
        } else {
            right = mid - 1; // Narrow down the search to the left half
        }
    }

    return -1; // Return -1 if the element is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int target = 40;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
