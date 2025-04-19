#include <iostream>
using namespace std;

// Iterative heapify function
void heapify(int arr[], int n, int i) {
    while (true) {
        int largest = i;  
        int left = 2 * i + 1;  
        int right = 2 * i + 2;  

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)  // If no swaps are needed, exit
            break;

        swap(arr[i], arr[largest]);
        i = largest;  // Move down to the affected subtree
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move max element to end
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
