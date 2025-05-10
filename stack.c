#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#define size 30

int stack[size];
int top = -1;

// Push operation for the stack
void push(int element) {
   if(top == size - 1) {
     printf("STACK FULL\n");
     return;  
   }   
   stack[++top] = element;
}

// Pop operation for the stack
int pop() {
   int element = INT_MIN;
   if(top == -1) {
      return element; // Stack underflow
   }
   element = stack[top];
   top--;
   return element;
}

// Check if the stack is full
int isFull() {
     return top == size - 1;
}

// Check if the stack is empty
int isEmpty() {
   return top == -1;
}

// Main function to evaluate postfix expression
int main() {
  char postfix[30];
  int i = 0;
  char c;
  int op2, op1, res;
  char opr;

  printf("Enter your postfix expression (use space to separate terms and end with $):\n");
  
  // Read the postfix expression until '$'
  while((c = getchar()) != '$') {
     postfix[i] = c;
     i++;
  }

  printf("Your input is :\n");
  for(int k = 0; k < i; k++) {
      printf("%c", postfix[k]);
  }
  printf("\n");

  // Process the postfix expression
  for(int j = 0; j < i; j++) {
     if(isdigit(postfix[j])) {
       // Push operand to the stack
       push(postfix[j] - '0');  // Convert character to integer
     }
     else if(postfix[j] == ' ') {
       // Ignore spaces
       continue;
     }
     else {
       // Operand (operator) case: pop two elements and perform the operation
       opr = postfix[j];
       op2 = pop(); 
       op1 = pop();
       
       // Perform operation based on operator
       if(opr == '+') { 
         res = op1 + op2;
       }
       else if(opr == '-') { 
         res = op1 - op2;
       }  
       else if(opr == '*') { 
         res = op1 * op2;
       }  
       else if(opr == '/') {
         if(op2 == 0) {
           printf("Error: Division by zero!\n");
           return -1;
         }
         res = op1 / op2;
       }  
       else if(opr == '%') {
         if(op2 == 0) {
           printf("Error: Modulo by zero!\n");
           return -1;
         }
         res = op1 % op2;
       }  
       // Push the result back onto the stack
       push(res);
     }
  }

  // Final result is the last element in the stack
  int ans = pop();
  if (!isEmpty()) {
    printf("Error: Invalid postfix expression\n");
    return -1;
  }
  printf("Answer = %d\n", ans);

  return 0;
}