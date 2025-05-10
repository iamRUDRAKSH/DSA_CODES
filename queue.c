#include<stdio.h>
#include<limits.h>

#define MAX 20

int queue[MAX] = {INT_MIN};  // Initialize all elements to INT_MIN
int rear = -1;
int front = -1;

void enqueue(int item) {
    if (rear == MAX - 1) {  // Queue Overflow
        printf("Queue Overflow \n");
    } else {
        if (front == -1) {
            front = 0;  // Queue was empty
        }
        rear++;
        queue[rear] = item;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {  // Queue Underflow
        printf("Queue Underflow \n");
    } else {
        printf("Element deleted from queue is: %d\n", queue[front]);
        front++;  // Move the front pointer to the next element
    }
}

int isFull() {
    if (rear == MAX - 1) {
        return 1;  // The queue is full
    }
    return 0;
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;  // The queue is empty
    }
    return 0;
}

void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(45);
    printQueue();
    enqueue(55);
    printQueue();
    enqueue(65);
    printQueue();
    enqueue(75);
    printQueue();
    enqueue(85);
    printQueue();

    dequeue();
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    printQueue();

    return 0;
}