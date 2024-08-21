#include <iostream>
#include <string> // Include the string header
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s + e) / 2;
    int *left = new int[mid - s + 1];
    int *right = new int[e - mid];
    int i = 0, j = 0, k = s;
    for (int i = s; i <= mid; i++){
        left[i - s] = arr[i];
    }
    for (int j = mid + 1; j <= e; j++){
        right[j - mid - 1] = arr[j];
    }
    i = s;
    j = mid + 1;
    while (i <= mid && j <= e){
        if (left[i - s] <= right[j - mid - 1]){
            arr[k] = left[i - s];
            i++;
            k++;
        }
        else{
            arr[k] = right[j - mid - 1];
            j++;
            k++;
        }
    }
    while (i <= mid){
        arr[k] = left[i - s];
        i++;
        k++;
    }
    while (j <= e){
        arr[k] = right[j - mid - 1];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void merge_sort(int *arr, int s, int e){
    if (s < e) {
        int mid = (s + e) / 2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid + 1, e);
        merge(arr, s, e);
    }    
}

int main() {
    int arr[] = {72, 12, 62, 82, 92, 42, 52, 2};
    int n = sizeof(arr)/sizeof(int);
    merge_sort(arr, 0 , n-1);
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    } 
    return 0;
}
