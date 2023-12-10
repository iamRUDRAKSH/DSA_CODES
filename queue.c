/*Queue
Rudraksh Charhate
I division */

#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#define MAX 20

int queue[MAX] = {INT_MIN};
int rear = -1;
int front = -1;

void enqueue(int item) {
  if(rear == MAX - 1)
    printf("Queue Overflow \n");
  else {
    if (front == - 1)
      front = 0;
    rear = rear + 1;
    queue[rear] = item;
  }
}

void dequeue() {
  if(front == - 1|| front > rear) {
    printf("Queue Underflow \n");
    return ;
  }
  else {
    printf("Element deleted from queue is : %d\n", queue[front]);
    front = front + 1;
  }
  return;
}

int isFull() {
  if(rear == MAX-1)
    return 1;
  else
    return 0;
}

int isEmpty() {
  if(front > rear || front == -1)
    return 1;
  else
    return 0;
}

void print() {
  for(int i = front; i <= rear;i++) {
    if(queue[i] != INT_MIN) {
      printf("%d ", queue[i]);
    }
  }
  printf("\n");
  return; 
}     
int main() {
  
  enqueue(45);
  print();
  enqueue(55);
  print();
  enqueue(65);
  print();
  enqueue(75);
  print();
  enqueue(85);
  print();
  dequeue();
  print();
  dequeue();
  print();
  dequeue();
  print();

return 0;
}  
