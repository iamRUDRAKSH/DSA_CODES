#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor
    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Enqueue operation
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % capacity;
        size++;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    // Peek front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Optional: display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();

    cout << "Front element after dequeue: " << q.getFront() << endl;

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // This one should get rejected (queue full)
    
    q.display();

    return 0;
}