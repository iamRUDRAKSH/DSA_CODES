//Alternate Bubble sort

#include<stdio.h>

int main() {

  int n;
  printf("Enter number of terms : ");
  scanf("%d", &n);

  int A[n];
  printf("Enter the numbers :\n");
  for(int i = 0;i < n;i++) {
    scanf("%d", &A[i]);
  }

  for(int i = 0;i < n - 1;i++) {
    if(i % 2 == 0) {
      int max = A[i%2], imax = i%2;
      for(int j = 1;j < n-(i/2);j++) {
        if(A[j] > max) {
          max = A[j];
          imax = j;
        }
      }
      int temp = A[imax];
      A[imax] = A[n-1-(i/2)];
      A[n-1-(i/2)] = temp;
    }

    else {
      int min = A[n-2-(i/2)], imin = n-2-(i/2) ;
      for(int j = n-2-(i/2);j >= i/2 ;j--) {
        if(A[j] < min) {
          min = A[j];
          imin = j;
        }
      }
      int temp = A[imin];
      A[imin] = A[i/2];
      A[i/2] = temp;
    }
    for(int k = 0;k < n;k++) {
      printf("%d\t", A[k]);
    }
    printf("\n");
  }
return 0;
}
