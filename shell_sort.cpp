#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 5, 9, 8, 7, 30, 39};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int interval = n / 2; // Start with a gap of half the size of the array

    // Shell Sort implementation
    while (interval >= 1) {
        // Perform insertion sort for the current interval
        for (int i = interval; i < n; i++) {
            int t = arr[i]; // Store the current element
            int j;
            // Shift elements to the right to make room for t
            for (j = i - interval; j >= 0 && arr[j] > t; j -= interval) {
                arr[j + interval] = arr[j];
            }
            arr[j + interval] = t; // Place the current element in its position
        }

        // Output the array after each interval pass (optional)
        cout << "Array after interval " << interval << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        // Reduce the interval
        interval /= 2;
    }
    return 0;
}
