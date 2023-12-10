#include<stdio.h>

int main() {
  int num;
  printf("Enter your number : ");
  scanf("%d", &num);

  int n1 = 1, n2 = 1, n3;
  if(num < 1) {
    printf("Invalid entry");
  }
  else if(num == 1 || num == 2) {
    printf("1");
  }
  else {
    for(int i = 2;i < num;i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    printf("%d", n3);
  }
  return 0;
}
