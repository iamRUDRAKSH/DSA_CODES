//Sanskruti Dongare
//FY23I010

#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#define size 30

char *cart[size];
int top = -1;
char *list[] = {"Mobile", "TV", "Tshirt", "Shirt", "Pant", "Headphone"};

void add(int aa) {
   int rr = aa - 1;
   if(top == size - 1) {
     printf("Cart is FULL\n");
     return;
   }
   cart[++top] = list[rr];
   return;
}
void nikal() {
   if(top == -1) {
      printf("Cart is EMPTY\n");
      return;
   }
   printf("%s is removed from the cart\n", cart[top]);
   top--;
   return;
}
void check() {
     printf("%s\n", cart[top]);
     return;
}

int main() {

  for(int i = 0;i < 6;i++){
    printf("%d %s\n", i+1,list[i]);
  }
  //Addition and removal of elements in array
  int flag = 1;
  do {
        while(1) {
    char ans = 'z';
    printf("Press a to add or press r to remove or c to check top item:\n");
    scanf("%c", &ans);
    if(ans == 'a'){
        int m;
        printf("Enter the serial no. of item you want to add :\n");
        scanf("%d", &m);
        add(m);
        break;
    }

    if(ans == 'r'){
        nikal();
        break;
    }

    if(ans == 'c'){
        check();
        break;
    }
        }
    printf("Press 1 if you want to continue else press 0 :\n");
    scanf("%d", &flag);
  }while(flag == 1);

  printf("Items in your cart are\n");
  for(int j = 0; j <= top; j++) {
    printf("%s\n", cart[j]);
  }
return 0;
}
