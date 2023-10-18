//merge 2 sorted arrays

#include<stdio.h>

int  main() {
  int n, m;
  printf("Number of elemenst in first array : ");
  scanf("%d", &n);
  printf("Number of elemenst in 2nd array : ");
  scanf("%d", &m);
  int A[n], B[m], C[m+n];
  printf("Enter values in 1st array in ascending order :\n");
  for(int i = 0;i < n;i++) {
      scanf("%d", &A[i]);
   }
    printf("Enter values in 2nd array in ascending order :\n");
  for(int i = 0;i < m;i++) {
      scanf("%d", &B[i]);
   }
   printf("1st array is :\n");
   for(int i = 0;i < n;i++) {
      printf("%d\t", A[i]);
   }
   printf("2nd array is :\n");
   for(int i = 0;i < m;i++) {
      scanf("%d\t", B[i]);
   }
   int i=j=k=0;
   while(i < n && j < m) {
     if(A[i] >= B[j] {
     C[k] = B[j];
     j++;
     }
     else {
     C[k] = A[i];
     i++;
     }
     k++;
   }
   while(i < n) {
     C[k] = A[i];
     i++;
     k++;
   }
   while(j < m) {
     C[k] = B[j];
     j++;
     k++;
   }
   for(int z = 0;z < m+n;z++) {
       printf("%d\t", C[z]);
    }
return 0;
}
