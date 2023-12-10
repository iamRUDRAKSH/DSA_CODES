//E-shopping 2.0
//Rudraksh Charhate

#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>
#define size 30

char *cart[size];
int top = -1;

void check() {
     if(top == -1) {
       printf("Cart is Empty");
       return;
     }
     printf("%s\n", cart[top]);
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

int main() {

  printf("Type '1' to check top item\n");
  printf("Type '2' to remove item\n");
  printf("Type '3' to add new item\n");
  printf("Type the name of item you would like to add\n");
  int ans = 1;
  do {
    int option;
    scanf("%s", &option);
   switch(option){
       case 1 : {
         check();
         break;
       }
       case 2 :{
         nikal();
         break;
       }
       case 3 :{
          if(top == size - 1) {
             printf("Cart is FULL\n");
          }
          else {
            char maal[20];
            scanf("%s", maal);
            cart[++top] = maal;
          }
          break;
       }
    }
    printf("Enter 1 to continue else press 0 :");
    scanf("%d", &ans);
  }while(ans == 1);

  for(int i = 0;i <= top;i++) {
    printf("%s\n", cart[i]);
  }
return 0;
}
