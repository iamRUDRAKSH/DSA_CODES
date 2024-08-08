#include<iostream>
using namespace std;

int* insertion_sort(int* A, int n){
    int i, j;
    for (i = 1; i < n; i++) {
        int t = A[i];
        for(j = i - 1; j >= 0; j--){
            if(A[j] > t)
                A[j + 1] = A[j];
            else
                break;
        }
        A[j + 1] = t;
    }
    return A;
}

void print_array(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    int A[] = {99, 88, 77, 55, 66, 44, 33, 11, 112, 91, 3, 1};
    int n = sizeof(A)/sizeof(A[0]);
    insertion_sort(A, n);
    print_array(A, n);
}