#include<iostream>
using namespace std;

int find_max(int *a, int n){
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void radix_sort(int *a, int n){
    int max = find_max(a, n);
    for(int exp = 1; (max/exp) > 0; exp *= 10){
        int output[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            int digit = (a[i]/exp)%10;
            count[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (a[i]/exp)%10;
            count[digit] -= 1;
            output[count[digit]] = a[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] = output[i];
        }
    }
}

int main(){
    int a[] = {12, 5, 7, 8, 19, 34, 24, 55, 11, 3};
    int n = sizeof(a)/sizeof(int);
    radix_sort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}