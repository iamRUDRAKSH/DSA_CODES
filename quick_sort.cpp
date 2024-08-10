#include<iostream>
using namespace std;

int partition(int start_index, int end_index, int* arr, int n);

void quick_sort(int start_index, int end_index, int* arr, int n){
    int j;
    if (start_index < end_index){
        j = partition(start_index, end_index, arr, n);
        quick_sort(start_index, j - 1, arr, n);
        quick_sort(j + 1, end_index, arr, n);
    }
}

int partition(int start_index, int end_index, int* arr, int n){
    int pivot = arr[start_index];
    int low = start_index;
    int high = end_index;

    while (low <= high) {
        while (low <= end_index && arr[low] <= pivot) {
            low++;
        }
        while (high >= start_index && arr[high] > pivot) {
            high--;
        }
        if (low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }

    int temp = arr[start_index];
    arr[start_index] = arr[high];
    arr[high] = temp;
    return high;
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {17, 7, 29, 20, 2, 8, 25, 28, 1, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(0, n - 1, arr, n);
    print_array(arr, n);
    return 0;
}
