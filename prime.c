#include<stdio.h>

int main() {

    int n;
    printf("Enter your number : ");
    scanf("%d", &n);
    if(n >= 0) {
      if(n == 0 || n == 1) {
        printf("Invalid entry");
      }
      else if(n == 2) {
        printf("2 ");
      }
      else if(n <= 4) {
        printf("2 3 ");
      }
      else {
        int flag = 1;
        printf("2 3 ");
        for(int i = 5;i <=n;i = i + 2) {
            for(int j = i-2;j > 1;j = j - 2) {
                if(i % j == 0) {
                   flag = 0;
                   break;
                }
                }
                if(flag == 1) {
                   printf("%d ", i);
             }
             flag = 1;
         }
       }
    }
return 0;
}
