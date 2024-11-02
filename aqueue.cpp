#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % capacity;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element: " << q.getFront() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl;
    return 0;
}
