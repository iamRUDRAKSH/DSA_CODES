//selection sort

#include<stdio.h>

int main() {
 //Initiation of array
 int n;
 printf("How many values : ");
 scanf("%d", &n);
 int A[n];
 printf("Enter vlaues in the array :\n");
 for(int i = 0; i < n;i++) {
    scanf("%d", &A[i]);
 }
 //Sorting of array
 int max = A[0],imax = 0, i, j, temp;
 for(i = 0;i < n - 1;i++) {
   for(j = 0;j < n -i;j++) {
      if(A[j] > max) {
        max = A[j];
        imax = j;
      }
   }
   temp = A[imax];
   A[imax] = A[n-1-i];
   A[n-1-i] = temp;

   max = A[0];
   imax = 0;
 }
  for(int i = 0; i < n;i++) {
    printf("%d ", A[i]);
 }
return 0;
}
