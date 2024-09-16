#include<iostream>
using namespace std;

// Function prototype for partitioning the array
int partition(int start_index, int end_index, int* arr, int n);

// Quick sort function to recursively sort the array
void quick_sort(int start_index, int end_index, int* arr, int n){
    int j;
    if (start_index < end_index) {
        // Partition the array and get the pivot index
        j = partition(start_index, end_index, arr, n);
        // Recursively sort the subarrays
        quick_sort(start_index, j - 1, arr, n);
        quick_sort(j + 1, end_index, arr, n);
    }
}

// Partition function to rearrange elements around a pivot
int partition(int start_index, int end_index, int* arr, int n){
    int pivot = arr[start_index]; // Choose the first element as the pivot
    int low = start_index + 1; // Start from the element right after the pivot
    int high = end_index; // Start from the end of the array

    while (low <= high) {
        // Move low index to the right while the element is less than or equal to the pivot
        while (low <= end_index && arr[low] <= pivot) {
            low++;
        }
        // Move high index to the left while the element is greater than the pivot
        while (high >= start_index && arr[high] > pivot) {
            high--;
        }
        // Swap elements if low index is less than high index
        if (low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }

    // Swap the pivot element with the element at the high index
    int temp = arr[start_index];
    arr[start_index] = arr[high];
    arr[high] = temp;
    return high; // Return the index of the pivot element
}

// Function to print the array elements
void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {17, 7, 29, 20, 2, 8, 25, 28, 1, 72}; // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    quick_sort(0, n - 1, arr, n); // Perform quicksort
    print_array(arr, n); // Print the sorted array
    return 0;
}
