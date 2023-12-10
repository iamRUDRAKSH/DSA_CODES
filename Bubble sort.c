//Bubble sort 

#include<stdio.h>
int n;
printf("How many values : ");
scanf("%d", &n);
int A[n];
printf("Enter vlaues in the array :\n");
for(int i = 0; i < n;i++)
    scanf("%d", &A[i]);

for(int i = 0;i < n-1;i++) {
 
  for(int j = 0;j < n - i;j++) {
     int temp = A[j];
     if(A[j+1] < A[j]) {
        A[j] = A[j+1];
        A[j+1] = temp;
     }
   }
 }
printf("Sorted array is :\n");
for(int i = 0; i < n;i++) 
    printf("%d"; A[i]);
return 0;
}




