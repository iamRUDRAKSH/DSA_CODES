/*Stack
Rudraksh Charhate
I division */

#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#define size 30

int stack[size];
int top = -1;

void push(int element) {
   if(top == size - 1) {
     printf("STACK FULL");
     return;  
   }   
   stack[++top] = element;
   return;
}
int pop() {
   int element = INT_MIN;
   if(top == -1) {
      return element;
   }
   element = stack[top];
   top--;
   return element;
}   
int isFull() {
     return top == size - 1;
}
int isEmpty() {
   return top == -1;
}
int main() {
  char postfix[30];
  int i = 0;
  char c;
  int op2, op1, res;
  char opr;
  printf("Enter your terms :\n");
  while((c = getchar()) != '$') {
     postfix[i] = c;
     i++;
  }
  printf("Your input is :\n");
  for(int k = 0;k < i;k++) {
      printf("%c", postfix[k]);
  }
  printf("\n");
  for(int j = 0;j < i;j++) {
     if(isdigit(postfix[j])) {
     push(postfix[j] - '0');
     }
     else {
       opr = postfix[j];
       op2 = pop(); 
       op1 = pop();
       
       if(opr == '+') { 
         res= op1 + op2;
       }
       if(opr == '-') { 
         res= op1 - op2;
       }  
       if(opr == '*') { 
         res= op1 * op2;
       }  
       if(opr == '/') {
         res= op1 / op2;
       }  
       if(opr == '%') {
         res= op1 % op2;
       }  
       push(res);
}
}
 int ans = pop();
 printf("Answer = %d", ans);
return 0;
} 